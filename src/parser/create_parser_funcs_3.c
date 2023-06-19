#include "../../includes/minishell.h"

void create_parser_tokens(t_lexer_token **lexer_tokens, ArrayList *parser_tokens, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (is_joinable(lexer_tokens[i]->type))
		{
			open_quotes(lexer_tokens, parser_tokens, &i, size);
			continue;
		} else if (lexer_tokens[i]->type == WHITE_SPACE)
			add_white_space(parser_tokens);
		else if (lexer_tokens[i]->type == LESS_THAN)
			add_input_redirect(parser_tokens);
		else if (lexer_tokens[i]->type == GREATER_THAN)
			add_output_redirect(parser_tokens);
		else if (lexer_tokens[i]->type == LESS_THAN_LESS_THAN)
			add_herdoc(parser_tokens);
		else if (lexer_tokens[i]->type == GREATER_THAN_GREATER_THAN)
			add_append_output(parser_tokens);
		else if (lexer_tokens[i]->type == PIPE)
			add_pipe(parser_tokens);
		i++;
	}
}
