/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:55:23 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/29 19:55:24 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse_readline(t_shell *minishell)
{
	get_line(minishell);
	if (minishell->input == NULL)
		return ;
	add_history(minishell->input);
	tokenize(minishell);
	parse_tokens(minishell);
}

void	get_line(t_shell *minishell)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	minishell->input = readline("$> ");
	if (!minishell->input)
	{
		printf("\033[1A\033[3Cexit\n");
		exit(1);
	}
	else if (*minishell->input == '\0')
	{
		free(minishell->input);
		minishell->input = NULL;
		minishell->cant_execute = 1;
	}
	else if (!ft_is_ascii(minishell->input))
	{
		free(minishell->input);
		minishell->input = NULL;
		minishell->cant_execute = 1;
	}
}
