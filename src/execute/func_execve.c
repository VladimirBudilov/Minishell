#include "../../includes/minishell.h"

//решить вопрос с ошибкой в execve WIFEXITED(status)

void ex_func(t_parser_token **token_key, t_shell *shell, char **envp)
{
	char **argv;
	char **path;
	int pid;
	int status;
	int i;

	if (token_key[0]->main_type == EXECUTABLE)
	{
		argv = ft_split(shell->input, ' ');
		pid = fork();
		if(pid == 0)
		{
			execve(token_key[0]->content, argv, envp);
			free_arr(argv);
			exit(EXIT_FAILURE);
		}
		waitpid(pid, &status, 0);
		return ;
	}


	argv = ft_split(shell->input, ' ');
	path = ft_split(ft_strdup(get_value_by_key(shell->env,"PATH")), ':');
	i = 0;
	pid = fork();
	if(pid == 0)
	{

		while(i < get_array_size(path))
		{
			if(access(ft_strjoin(ft_strjoin(ft_strdup(path[i]), "/"), token_key[0]->content), X_OK) == 0)
			{
				execve(ft_strjoin(ft_strjoin(ft_strdup(path[i]), "/"), token_key[0]->content), argv, envp);
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





