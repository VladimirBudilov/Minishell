#include "../../includes/minishell.h"


void create_parser_tokens(t_lexer_token **lexer_tokens, t_array_list *parser_tokens, int size)
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
            add_parser_token(parser_tokens, NEW_SPACE, " ");
		else if (lexer_tokens[i]->type == LESS_THAN)
            add_parser_token(parser_tokens, REDIRECT_INPUT, "");
		else if (lexer_tokens[i]->type == GREATER_THAN)
            add_parser_token(parser_tokens, REDIRECT_OUTPUT, "");
		else if (lexer_tokens[i]->type == LESS_THAN_LESS_THAN)
            add_parser_token(parser_tokens, HEREDOC , "");
		else if (lexer_tokens[i]->type == GREATER_THAN_GREATER_THAN)
            add_parser_token(parser_tokens,REDIRECT_APPEND_OUTPUT, "");
		else if (lexer_tokens[i]->type == PIPE)
            add_parser_token(parser_tokens, PIPELINE, "|");
		i++;
	}
}

void add_parser_token(t_array_list *tokens_array, enum parser_type type, const char *content) {
    t_parser_token *token;

    token = malloc(sizeof(t_parser_token));
    token->main_type = type;
    token->sub_type = 0;
    token->flags = 0;
    token->content = ft_strdup(content);
    add_element(tokens_array, token);
}
