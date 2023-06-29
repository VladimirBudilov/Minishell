/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:56:17 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/29 19:56:19 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokenize(t_shell *shell)
{
	char				*input;
	int					i;
	t_tokenizer_output	**po_array;

	i = 0;
	input = shell->input;
	po_array = (t_tokenizer_output **) shell->tokenizer_array->array;
	while (*input)
	{
		if (*input == ' ')
			input = add_token(shell, (po_array[i++]
						= tokenize_white_space(input, shell)));
		else if (*input == '\'')
		input = add_token(shell, (po_array[i++]
						= tokenize_single_quote(input, shell)));
		else if (*input == '\"')
		input = add_token(shell, (po_array[i++]
						= tokenize_double_quote(input, shell)));
		else if (*input == '<')
		input = add_token(shell, (po_array[i++]
						= tokenize_less(input, shell)));
		else if (*input == '>')
		input = add_token(shell, (po_array[i++]
						= tokenize_greater(input, shell)));
		else if (*input == '|')
		input = add_token(shell, (po_array[i++] = tokenize_pipe(input, shell)));
		else if (*input == '$')
		input = add_token(shell, (po_array[i++]
						= tokenize_dollar(input, shell)));
		else if (ft_isascii(*input) && !is_breaking_character(*input))
		input = add_token(shell, (po_array[i++]
						= tokenize_bare_word(input, shell)));
		else
			break ;
	}
}
