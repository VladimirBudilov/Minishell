#include "includes/minishell.h"

int	command_func3(t_parser_token **token_key, t_array_list \
		*parser_tokens, t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	if (token_key[i]->main_type == BIlD_IN)
		execute_builtin(parser_tokens, shell, i);
	else if (token_key[i]->main_type == EXECUTABLE || \
			token_key[i]->main_type == EXECUTABLE_PATH)
		ex_func(parser_tokens, shell, envp);
	else
	{
		ft_putstr_fd("shell: ", 2);
		ft_putstr_fd(token_key[i]->content, 2);
		ft_putstr_fd(": command not found\n", 2);
		err_no = 127;
		return (0);
	}
	return (1);
}

void	command_func2(t_parser_token **token_key, t_array_list \
		*parser_tokens, t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	execute_redir(parser_tokens, shell);
	if (shell->only_here_doc)
		exit(0);
	if (token_key[i]->main_type == BIlD_IN)
		execute_builtin(parser_tokens, shell, i);
	else if (token_key[i]->main_type == EXECUTABLE || \
					token_key[i]->main_type == EXECUTABLE_PATH)
		ex_func(parser_tokens, shell, envp);
	else
	{
		ft_putstr_fd("shell last: ", 2);
		ft_putstr_fd(token_key[i]->content, 2);
		ft_putstr_fd(": command not found\n", 2);
		err_no = 127;
		exit(0);
	}
	exit(0);
}

void	command_func(t_shell *shell, char **envp)
{
	int				pid;
	t_parser_token	**token_key;
	t_array_list	*parser_tokens;

	parser_tokens = shell->parser_tokens_array;
	if (shell->cant_execute)
		return ;
	token_key = (t_parser_token **)shell->parser_tokens_array->array;
	if (has_redir(shell->parser_tokens_array))
	{
		pid = fork();
		if (pid == 0)
			command_func2(token_key, parser_tokens, shell, envp);
		waitpid(pid, NULL, 0);
		return ;
	}
	else
	{
		if (!command_func3(token_key, parser_tokens, shell, envp))
			return ;
	}
}