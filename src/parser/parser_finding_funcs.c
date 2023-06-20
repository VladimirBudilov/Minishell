#include "../../includes/minishell.h"

void free_array(char **paths);

void find_execver(ArrayList *parser_tokens_array, t_shell *shell)
{
	t_parser_token **parser_tokens;
	char **paths;
	int size;
    char *temp;

	parser_tokens = (t_parser_token **) (parser_tokens_array->array);
    temp = ft_strdup(get_value_by_key(shell->env, "PATH"));
	paths = ft_split(temp, ':');
	size = get_array_size(paths);
	if (size == 0)
	{
		error("PATH is not set");
		return;
	}
	add_execver(parser_tokens, paths, parser_tokens_array->size, size);
    free(temp);
    free_array(paths);
}

void free_array(char **paths) {
    int i;

    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);

}

void add_execver(t_parser_token **parser_tokens, char **paths, int size_main, int size_sub)
{
	int i;
	int j;
	struct stat s;

	i = 0;
	while (i < size_main)
	{
		j = 0;
		char *path;

		while (j < size_sub)
		{

			path = ft_strjoin(ft_strjoin(ft_strdup(paths[j]), "/"), parser_tokens[i]->content);
			if (access(path, X_OK) == 0
			&& parser_tokens[i]->main_type == WORDLIST)
			{
				stat(path, &s);
				if (S_ISREG(s.st_mode))
				{
                    free(path);
					parser_tokens[i]->main_type = EXECUTABLE;
					break;
				}
			}
            free(path);
			j++;
		}
		i++;
	}
}

void find_dirs(ArrayList *parser_tokens)
{
	int i;
	t_parser_token **tokens;

	tokens = (t_parser_token **) parser_tokens->array;
	i = 0;
	while (i < parser_tokens->size)
	{
		if (tokens[i]->main_type == WORDLIST)
		{
			if (is_directory(tokens[i]->content))
			{
				tokens[i]->main_type = DIRECTORY;
			}
		}
		i++;
	}
}

int is_directory(char *path)
{
	if (access(path, F_OK | R_OK | X_OK) == 0)
	{
		struct stat pathStat;

		if (stat(path, &pathStat) != 0)
		{
			return 0;
		}
		return S_ISDIR(pathStat.st_mode);
	}
	return 0;
}

void find_build_in(ArrayList *parser_tokens)
{
	int i;
	t_parser_token **tokens;

    tokens = (t_parser_token **) parser_tokens->array;
    i = 0;
    while (i < parser_tokens->size)
    {
        if(tokens[i]->main_type == WORDLIST)
        {
			add_echo(tokens[i], parser_tokens, i);
            add_cd(tokens[i]);
            add_pwd(tokens[i]);
            add_exprt(tokens[i]);
            add_unset(tokens[i]);
            add_envp(tokens[i]);
            add_exit(tokens[i]);
        }
        i++;
    }
}
