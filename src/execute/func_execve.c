#include "../../includes/minishell.h"

//решить вопрос с ошибкой в execve WIFEXITED(status)

char **new_arr(t_array_list *line, int index)
{
	int i;
	t_parser_token **token_key;

	i = 0;
	token_key = (t_parser_token **)line->array;
	char **arr = (char **)malloc(sizeof(char *) * (line->size - index + 1));
	while (index < line->size)
	{
		if (token_key[index]->main_type == NEW_SPACE)
			index++;
		arr[i] = ft_strdup(token_key[index]->content);
		index++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}


void read_2d_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void ex_func(t_array_list *line, t_shell *shell, char **envp)
{
	char **argv;
	char **path;
	int pid;
	int status;
	int i;
	t_parser_token **token_key;

	token_key = (t_parser_token **)line->array;
	int index = 0;

	if (token_key[index]->main_type == NEW_SPACE)
		index++;

	if (token_key[index]->main_type == EXECUTABLE)
	{
		argv = new_arr(line, index);
		pid = fork();
		if(pid == 0)
		{
			execve(token_key[index]->content, argv, envp);
			free_arr(argv);
			exit(EXIT_FAILURE);
		}
		waitpid(pid, &status, 0);
		return ;
	}


	argv = new_arr(line, index);
	path = ft_split(ft_strdup(get_value_by_key(shell->env,"PATH")), ':');
	i = 0;
	pid = fork();
	if(pid == 0)
	{

		while(i < get_array_size(path))
		{
			if(access(ft_strjoin(ft_strjoin(ft_strdup(path[i]), "/"), token_key[index]->content), X_OK) == 0)
			{
				execve(ft_strjoin(ft_strjoin(ft_strdup(path[i]), "/"), token_key[index]->content), argv, envp);
				break ;
			}
			i++;
		}
		free_arr(argv);
		free_arr(path);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
}





