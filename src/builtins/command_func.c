/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:21:20 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/03 13:33:05 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		g_err_no = 127;
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
		g_err_no = 127;
		exit(0);
	}
	exit(0);
}

void	command_func(t_shell *shell, char **envp)
{
	int				pid;
	t_parser_token	**token_key;
	t_array_list	*parser_tokens;

	printf("command_func\n");
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

void	execute_builtin(t_array_list *token_array, t_shell *shell, int i)
{
	t_hashmap		**hashmap_key;
	t_parser_token	**token_key;

	token_key = (t_parser_token **)token_array->array;
	hashmap_key = (t_hashmap **)shell->env->array;
	if (token_key[i]->sub_type == ECHO)
		echo_func(token_array);
	else if (token_key[i]->sub_type == ENVP)
		env_func(hashmap_key, token_array, shell);
	else if (token_key[i]->sub_type == CD)
		cd_func(hashmap_key, token_array, shell);
	else if (token_key[i]->sub_type == PWD)
		pwd_func();
	else if (token_key[i]->sub_type == EXIT)
		exit_func(token_array, shell);
	else if (token_key[i]->sub_type == EXPORT)
		export_func(hashmap_key, token_array, shell);
	else if (token_key[i]->sub_type == UNSET)
		unset_func(hashmap_key, token_array, shell);
}
