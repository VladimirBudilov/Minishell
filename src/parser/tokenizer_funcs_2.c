#include "../../includes/minishell.h"

t_tokenizer_output *tokenize_less(char *input) {
    t_tokenizer_output *po;
    t_token *t;

    po = malloc(sizeof(t_tokenizer_output));
    t = malloc(sizeof(t_token));
    if (*(input + 1) && *(input + 1) == '<') {
        t->type = LESS_THAN_LESS_THAN;
        t->content = "<<";
        po->string = input + 2;
        po->token = *t;
        return po;
    }
    t->type = LESS_THAN;
    t->content = "<";
    po->string = input + 1;
    po->token = *t;
    return po;
}

t_tokenizer_output *tokenize_pipe(char *input) {
    t_tokenizer_output *po;
    t_token *t;

    po = malloc(sizeof(t_tokenizer_output));
    t = malloc(sizeof(t_token));
    t->type = PIPE;
    t->content = "|";
    po->string = input + 1;
    po->token = *t;
    return po;
}

t_tokenizer_output *tokenize_greater(char *input) {
    t_tokenizer_output *po;
    t_token *t;

    po = malloc(sizeof(t_tokenizer_output));
    t = malloc(sizeof(t_token));
    if (*(input + 1) && *(input + 1) == '>') {
        t->type = GREATER_THAN_GREATER_THAN;
        t->content = ">>";
        po->string = input + 2;
        po->token = *t;
        return po;
    }
    t->type = GREATER_THAN;
    t->content = ">";
    po->string = input + 1;
    po->token = *t;
    return po;
}

t_tokenizer_output *tokenize_dollar(char *input)
{
    t_tokenizer_output *po;
    t_token *t;

    po = malloc(sizeof(t_tokenizer_output));
    t = malloc(sizeof(t_token));
    t->type = PIPE;
    t->content = "$";
    po->string = input + 1;
    po->token = *t;
    return po;
}