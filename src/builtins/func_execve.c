#include "../../includes/minishell.h"

void ex_func(t_parser_token **token_key, t_shell *shell, char **envp)
{
	char **argv;
	int pid;
    int status;

	argv = ft_split(shell->input, ' ');

	pid = fork();
	if(pid == 0)
	{
		execve(token_key[0]->content, argv, envp);
		free_arr(argv);
	}
    waitpid(pid, &status, 0);
}