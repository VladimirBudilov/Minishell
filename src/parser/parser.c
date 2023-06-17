#include "../../includes/minishell.h"


void add_white_space(ArrayList *parser_tokens);

void add_input_redirect(ArrayList *parser_tokens);

void add_output_redirect(ArrayList *parser_tokens);

void add_herdoc(ArrayList *parser_tokens);

void add_append_output(ArrayList *parser_tokens);

void add_pipe(ArrayList *parser_tokens);

void find_build_in(ArrayList *parser_tokens);

void find_execver(ArrayList *parser_tokens);

void validate_tokens(ArrayList *parser_tokens);

/*
 Open quote
 redo arraylist
 check build in
 check func in bin(execver)
 check pipe
 check redir

*/

void parse_tokens(t_shell *shell) {
    t_lexer_token **lexer_tokens;
    ArrayList *parser_tokens;
    int size;
    int i;

    i = 0;
    lexer_tokens = (t_lexer_token **) shell->lexer_tokens_array->array;
    parser_tokens = shell->parser_tokens_array;
    size = shell->lexer_tokens_array->size;
    if (size == 0)
        return;
    while (i < size)
    {
        if(is_joinable(lexer_tokens[i]->type))
        {
            open_quotes(lexer_tokens, parser_tokens, &i, size);
            continue;
        }
        else if(lexer_tokens[i]->type == WHITE_SPACE)
            add_white_space(parser_tokens);
        else if(lexer_tokens[i]->type == LESS_THAN)
            add_input_redirect(parser_tokens);
        else if(lexer_tokens[i]->type == GREATER_THAN)
            add_output_redirect(parser_tokens);
        else if(lexer_tokens[i]->type == LESS_THAN_LESS_THAN)
            add_herdoc(parser_tokens);
        else if(lexer_tokens[i]->type == GREATER_THAN_GREATER_THAN)
            add_append_output(parser_tokens);
        else if(lexer_tokens[i]->type == PIPE)
            add_pipe(parser_tokens);
        i++;
    }

/*    find_build_in(parser_tokens);
    find_execver(parser_tokens);
    validate_tokens(parser_tokens);*/

}

/*void validate_tokens(ArrayList *parser_tokens) {
    (void) parser_tokens;
}

void find_execver(ArrayList *parser_tokens) {
    (void) parser_tokens;

}

void find_build_in(ArrayList *parser_tokens) {

    (void) parser_tokens;

}*/

void add_pipe(ArrayList *parser_tokens) {

    t_parser_token *token;

    token = create_token(PIPELINE, "|");
    add_element(parser_tokens, token);

}

void add_append_output(ArrayList *parser_tokens) {

    t_parser_token *token;

    token = create_token(REDIRECT_APPEND_OUTPUT, ">>");
    add_element(parser_tokens, token);

}

void add_herdoc(ArrayList *parser_tokens) {

    t_parser_token *token;

    token = create_token(REDIRECT_INPUT, "<<");
    add_element(parser_tokens, token);
}

void add_output_redirect(ArrayList *parser_tokens) {

    t_parser_token *token;

    token = create_token(REDIRECT_OUTPUT, ">");
    add_element(parser_tokens, token);

}

void add_input_redirect(ArrayList *parser_tokens) {

    t_parser_token *token;

    token = create_token(REDIRECT_INPUT, "<");
    add_element(parser_tokens, token);
}

void add_white_space(ArrayList *parser_tokens) {

    t_parser_token *token;

    token = create_token(NEW_SPACE, " ");
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
    //printf("token->content = %s\n", token->content);
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


/*

minishell->token_array->array[] = {el1, el2, el3, el4, el5}
minishell->token_array->array->token - токен
*/