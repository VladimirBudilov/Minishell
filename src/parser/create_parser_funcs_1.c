#include "../../includes/minishell.h"

void add_append_output(ArrayList *parser_tokens)
{

	t_parser_token *token;

	token = create_token(REDIRECT_APPEND_OUTPUT, ">>");
	add_element(parser_tokens, token);

}

void add_herdoc(ArrayList *parser_tokens)
{

	t_parser_token *token;

	token = create_token(HEREDOC, "<<");
	add_element(parser_tokens, token);
}

void add_output_redirect(ArrayList *parser_tokens)
{
	t_parser_token *token;

	token = create_token(REDIRECT_OUTPUT, ">");
	add_element(parser_tokens, token);

}

void add_input_redirect(ArrayList *parser_tokens)
{
	t_parser_token *token;

	token = create_token(REDIRECT_INPUT, "<");
	add_element(parser_tokens, token);
}

void add_white_space(ArrayList *parser_tokens)
{
	t_parser_token *token;

	token = create_token(NEW_SPACE, " ");
	add_element(parser_tokens, token);
}