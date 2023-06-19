#include "../../includes/minishell.h"

void tokenize(t_shell *shell)
{
	char *input = shell->input;

	while (*input)
	{
		if (*input == ' ')
			input = add_token(shell, (tokenize_white_space(input)));
		else if (*input == '\'')
			input = add_token(shell, (tokenize_single_quote(input)));
		else if (*input == '\"')
			input = add_token(shell, (tokenize_double_quote(input, shell)));
		else if (*input == '<')
			input = add_token(shell, (tokenize_less(input)));
		else if (*input == '>')
			input = add_token(shell, (tokenize_greater(input)));
		else if (*input == '|')
			input = add_token(shell, (tokenize_pipe(input)));
		else if (*input == '$')
			input = add_token(shell, (tokenize_dollar(input, shell)));
		else if (ft_isascii(*input) && !is_breaking_character(*input))
			input = add_token(shell, tokenize_bare_word(input));
		else
			break;
	}
}
