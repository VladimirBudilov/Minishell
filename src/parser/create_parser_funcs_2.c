#include "../../includes/minishell.h"

void add_pipe(ArrayList *parser_tokens) {

    t_parser_token *token;

    token = create_token(PIPELINE, "|");
    add_element(parser_tokens, token);

}

int is_joinable(enum lexer_type type) {
    if(type == BARE_WORD || type == SINGLE_QUOTES || type == DOUBLE_QUOTES || type == DOLLAR)
        return 1;
    return 0;
}

void open_quotes(t_lexer_token **lexer_tokens, ArrayList *parser_tokens, int *i, int size) {

    t_parser_token *token;

    token = create_token(WORDLIST, lexer_tokens[*i]->content);
    add_element(parser_tokens, token);
    *i += 1;
    while (*i < size && is_joinable(lexer_tokens[*i]->type)) {
        join_words(lexer_tokens[*i], token);
        *i += 1;
    }
}

void join_words(t_lexer_token *lexer_token, t_parser_token *token)
{
    token->content = ft_strjoin(token->content, ft_strdup(lexer_token->content));
}

t_parser_token *create_token(enum parser_type type, char *content){
    t_parser_token *token;

    token = malloc(sizeof(t_parser_token));
    token->main_type = type;
    token->sub_type = 0;
    token->flags = 0;
    token->content = ft_strdup(content);
    return token;
}