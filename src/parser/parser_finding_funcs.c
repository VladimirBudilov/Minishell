#include "../../includes/minishell.h"

void find_execver(ArrayList *parser_tokens_array, t_shell *shell)
{
	t_parser_token **parser_tokens;
	char **paths;
	int size;

	parser_tokens = (t_parser_token **) (parser_tokens_array->array);
	paths = ft_split(ft_strdup(get_value_by_key(shell->env, "PATH")), ':');
	size = get_array_size(paths);
	if (size == 0)
	{
		error("PATH is not set");
		return;
	}
	add_execver(parser_tokens, paths, parser_tokens_array->size, size);
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
		while (j < size_sub)
		{
			if (access(ft_strjoin(ft_strjoin(paths[j], "/"), parser_tokens[i]->content), X_OK) == 0
			&& parser_tokens[i]->main_type == WORDLIST)
			{
				stat(ft_strjoin(ft_strjoin(paths[j], "/"), parser_tokens[i]->content), &s);
				if (S_ISREG(s.st_mode))
				{
					parser_tokens[i]->main_type = EXECUTABLE;
					break;
				} else
				{
					parser_tokens[i]->main_type = DIRECTORY;
					break;
				}
			}
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
