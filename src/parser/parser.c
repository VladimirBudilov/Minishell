#include "../../includes/minishell.h"

void parse_tokens(t_shell *shell)
{
	t_lexer_token **lexer_tokens;
	t_array_list *parser_tokens;
	int size;

	lexer_tokens = (t_lexer_token **) shell->lexer_tokens_array->array;
	parser_tokens = shell->parser_tokens_array;
	size = shell->lexer_tokens_array->size;
	if (size == 0)
		return;
	create_parser_tokens(lexer_tokens, parser_tokens, size);
	find_build_in(parser_tokens);
	find_execver(parser_tokens, shell);
	find_dirs(parser_tokens);
	//validate_tokens(parser_tokens);
}



















