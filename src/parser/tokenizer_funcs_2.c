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

t_tokenizer_output *tokenize_dollar(char *input, t_shell *shell)
{
    (void) shell;

    int i;
    t_tokenizer_output *po;
    t_token *t;

    i = 0;
    input++;
    po = malloc(sizeof(t_tokenizer_output));
    t = malloc(sizeof(t_token));

    t->content = ft_strdup("");
    if(*input == '?')
    {
        t->content = ft_itoa(shell->exit_code);
        t->type = DOLLAR;
        po->string = input + 1;
        po->token = *t;
        return po;
    }
    if(is_breaking_character(*input))
    {
        t->content = "$";
        t->type = DOLLAR;
        po->string = input + 1;
        po->token = *t;
        return po;
    }
    while (input[i] && !is_breaking_character(input[i]))
    {
        if(contain_key(shell->env, ft_strndup(input, i + 1)))
        {
            t->content = ft_strjoin(t->content, get_element_by_key(shell->env, ft_strndup(input, i + 1)));
            i++;
            break;
        }
        i++;
    }
    t->type = DOLLAR;
    po->string = input + i;
    printf("t->content: %s\n", t->content);
    printf("po->string: %s\n", po->string);
    po->token = *t;
    return po;
}
