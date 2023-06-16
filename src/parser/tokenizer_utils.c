#include "../../includes/minishell.h"

char *add_token(t_shell *shell, struct tokenizer_output *po) {
    add_element(shell->tokens_array, &po->token);
    return po->string;
}

char *open_dollar(char *input, t_shell *shell, t_token *t)
{
    int i;

    i = 0;
    if(input[i] == '?')
    {
        t->content = ft_strjoin(t->content, ft_itoa(shell->exit_code));
        return input + 1;
    }
    if(is_breaking_character(input[i]))
    {
        t->type = DOLLAR;
        t->content = ft_strjoin(t->content, "$");
        return input + 1;
    }
    while (input[i] && !(input[i] == '$' && input[i + 1] != '\"'))
    {
        if(contain_key(shell->env, ft_strndup(input, i + 1)))
        {
            t->content = ft_strjoin(t->content, get_element_by_key(shell->env, ft_strndup(input, i + 1)));
            return input + i + 1;
        }
        i++;
    }
    return input + i;
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
    char breaking_characters[] = "\'\"<>|$ \n\t"; // & if bonus.

    int size = sizeof breaking_characters / sizeof *breaking_characters - 1;
    for (int i = 0; i < size; i++) {
        if (c == breaking_characters[i])
            return 1;
    }
    return 0;
}