/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_func_unset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:47:48 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/01 15:34:00 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_position_of_element(t_hashmap **hashmap_key, char *key, t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->env->size)
	{
		if (!ft_strncmp(hashmap_key[i]->key, key, ft_strlen(key)))
			return (i);
		i++;
	}
	return (0);
}

void	unset_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell)
{
	int				i;
	t_parser_token	**token_key;

	i = 1;
	token_key = (t_parser_token **)line->array;
	if (line->size > 1)
	{
		if (!check_valid_arguments(token_key, shell))
		{
			err_no = 1;
			return ;
		}
	}
	while (i < line->size)
	{
		if (contain_key(shell->env, token_key[i]->content))
			delete_element(shell->env, get_position_of_element(hashmap_key, \
						token_key[i]->content, shell));
		i++;
	}
	err_no = 0;
}
