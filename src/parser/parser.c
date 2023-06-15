#include "../../includes/minishell.h"

void parse_tokens(t_shell *shell) {
    t_token **tokens;
    ArrayList *args;
    int size;
    int i;

    i = 0;
    tokens = (t_token **) shell->tokens_array->array;
    args = shell->args_array;
    size = shell->tokens_array->size;
    if (size == 0)
        return;
    while (i < size) {
        if (tokens[i]->type == BARE_WORD || tokens[i]->type == SINGLE_QUOTES || tokens[i]->type == DOUBLE_QUOTES ||
            tokens[i]->type == WHITE_SPACE) {
            add_element(args, create_token(WORDLIST, tokens[i]->content));
        }
        i++;
    }
}

t_parser_output *create_token(enum parser_type type, char *content){
    t_parser_output *token;

    token = malloc(sizeof(t_parser_output));
    token->main_type = type;
    token->content = ft_strdup(content);
    return token;
}

