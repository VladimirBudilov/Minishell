/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:15:21 by vbudilov          #+#    #+#             */
/*   Updated: 2023/07/01 11:15:22 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	has_path(t_shell *shell)
{
	if (get_value_by_key(shell->env, "PATH") == NULL)
	{
		err_no = 127;
		return (0);
	}
	return (1);
}