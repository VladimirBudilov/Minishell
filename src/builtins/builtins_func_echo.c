/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_func_echo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:15:37 by vchizhov          #+#    #+#             */
/*   Updated: 2023/06/30 16:26:13 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_size(t_array_list *line)
{
	if (line->size <= 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}

void	echo_func(t_array_list *line)
{
	int				check_n;
	int				i;
	t_parser_token	**token_key;

	i = 2;
	check_n = 0;
	err_no = 0;
	token_key = (t_parser_token **)line->array;
	if (token_key[0]->main_type == NEW_SPACE)
		i++;
	if (!check_size(line))
		return ;
	if (!(ft_strncmp(token_key[i]->content, "-n", 2)) \
			&& token_key[i]->content[2] == '\0')
	{
		check_n = 1;
		i += 2;
	}
	while (i < line->size)
	{
		ft_putstr_fd(token_key[i]->content, 1);
		i++;
	}
	if (!check_n)
		write(1, "\n", 1);
}
