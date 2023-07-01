/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_func_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:40:45 by vchizhov          #+#    #+#             */
/*   Updated: 2023/06/30 16:46:26 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_error(t_parser_token **token_key, int index)
{
	ft_putstr_fd("exit\n", 1);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(token_key[index]->content, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit(1);
}

int	check_number_arg(t_parser_token **token_key, t_shell *shell)
{
	int	i;
	int	j;

	i = 1;
	while (i < shell->parser_tokens_array->size)
	{
		j = 0;
		while (token_key[i]->content[j])
		{
			if (token_key[i]->content[j] == '-' && j == 0)
				j++;
			if (token_key[i]->content[j] == '+' && j == 0)
				j++;
			if (ft_isdigit(token_key[i]->content[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	exit_func(t_array_list *line, t_shell *shell)
{
	t_parser_token	**token_key;
	int				index;

	token_key = (t_parser_token **)line->array;
	index = 1;
	err_no = 0;
	if (check_number_arg(token_key, shell))
	{
		if (line->size <= 2)
		{
			ft_putstr_fd("exit\n", 1);
			exit(1);
		}
		else
		{
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			err_no = 1;
		}
	}
	else
		print_error(token_key, index);
}
