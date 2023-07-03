/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:18:48 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/29 18:18:50 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void error(char *message, t_shell *shell, int error)
{
	fprintf(stderr, "shell : %s\n", message);
	shell->cant_execute = 1;
	err_no = error;
}

int	redir_error(t_parser_token **parser_tokens, int i, t_shell *shell)
{
	if (parser_tokens[i + 1]->main_type == NEW_SPACE)
		i++;
	if (is_redir(parser_tokens[i + 1]))
	{
		syntax_error(shell);
		return (1);
	}
	return (0);
}

void	syntax_error(t_shell *shell)
{
	printf("shell: syntax error near unexpected token\n");
	shell->cant_execute = 1;
	err_no = 258;
}
