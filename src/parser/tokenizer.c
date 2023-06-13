#include "../../includes/minishell.h"

int is_breaking_character(char c) {
    char breaking_characters[] = "'\"<>|$ \n\t"; // & if bonus.

    int size = sizeof breaking_characters / sizeof *breaking_characters - 1;
    for (int i = 0; i < size; i++) {
        if (c == breaking_characters[i])
            return 1;
    }
    return 0;
}

t_tokenizer_output *tokenize_white_space(char *input) {
    t_tokenizer_output *po;
    t_token *t;
    int i;

    t = malloc(sizeof(t_token));
    po = malloc(sizeof(t_tokenizer_output));
    i = 0;
    while (input[i] && input[i] == ' ')
        i++;
    po->string = (input + i);
    t->type = WHITE_SPACE;
    t->content = " ";
    po->token = *t;
    return po;
}

t_tokenizer_output * tokenize_single_quote(char *input) {
    int i;
    t_tokenizer_output *po;
    t_token *t;

    t = malloc(sizeof(t_token));
    po = malloc(sizeof(t_tokenizer_output));
    i = 0;
    input++;
    while (input[i] && input[i] != '\'')
        i++;
    if (input[i] == 0)
        error("Unclosed single quote.");
    po->string = input + i + 1;
    t->type = SINGLE_QUOTES;
    t->content = ft_strndup(input, i);
    po->token = *t;
    return po;
}

t_tokenizer_output *tokenize_double_quote(char *input) {
    int i;
    t_tokenizer_output *po;
    t_token *t;

    t = malloc(sizeof(t_token));
    po = malloc(sizeof(t_tokenizer_output));
    i = 0;
    input++;
    while (input[i] && input[i] != '\"')
        i++;
    if (input[i] == 0)
        error("Unclosed double quote.");
    po->string = input + i + 1;
    t->type = DOUBLE_QUOTES;
    t->content = ft_strndup(input, i);
    po->token = *t;
    return po;
}

t_tokenizer_output *tokenize_bare_word(char *input) {
    t_tokenizer_output *po;
    t_token *t;

    if (is_breaking_character(*input))
        bug("Expected a bare word, but found a breaking character.");
    int i = 0;

    while (input[i] && !is_breaking_character(input[i]))
        i++;
    t = malloc(sizeof(t_token));
    po = malloc(sizeof(t_tokenizer_output));
    t->type = BARE_WORD;
    t->content = ft_strndup(input, i);
    po->string = input + i;
    po->token = *t;

    return po;
}

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

void tokenize(t_shell *shell) {
    char *input = shell->input;

    while (*input) {

        if (*input == ' ') {// White space.
            printf("White space.\n");
            input = add_token(shell, (tokenize_white_space(input)));
        }
        else if(*input == '\'')
        { // Single quote.
            input = add_token(shell, (tokenize_single_quote(input)));
        }
        else if(*input == '\"')
        { // Single quote.
            input = add_token(shell, (tokenize_double_quote(input)));
        }
        else if(*input == '<')
        {
            input = add_token(shell, (tokenize_less(input)));
        }
        else if(*input == '>')
        {
            input = add_token(shell, (tokenize_greater(input)));
        }
        else if(*input == '|')
        { // Pipe.
            input = add_token(shell, (tokenize_pipe(input)));
        }
        else if(*input == '$')
        { // Dollar.
            input = add_token(shell, (tokenize_dollar(input)));
        }
        else if (ft_isascii(*input) && !is_breaking_character(*input)) { // Bare word.
            input = add_token(shell, tokenize_bare_word(input));
        } else
            break;
    }
}


char *add_token(t_shell *shell, struct tokenizer_output *po) {
    add_element(shell->tokens_array, &po->token);
    return po->string;
}

char *ft_strndup(char *str, int n)
{
    char *dest;
    int i;

    i = 0;
    dest = malloc(sizeof(char) * (n + 1));
    while (str[i] && i < n)
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}





