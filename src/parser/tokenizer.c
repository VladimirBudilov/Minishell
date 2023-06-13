#include "../../includes/minishell.h"

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

int is_breaking_character(char c) {
    char breaking_characters[] = "'\"<>|$ \n\t"; // & if bonus.

    int size = sizeof breaking_characters / sizeof *breaking_characters - 1;
    for (int i = 0; i < size; i++) {
        if (c == breaking_characters[i])
            return 1;
    }
    return 0;
}






