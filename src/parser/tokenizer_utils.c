#include "../../includes/minishell.h"

char *add_token(t_shell *shell, struct tokenizer_output *po)
{
	add_element(shell->lexer_tokens_array, &po->token);
	return po->string;
}

int open_dollar(char *input, t_shell *shell, t_lexer_token *t)
{
    int i;
    char *temp;

    i = 1;
    if (input[i] == '?')
    {
        t->content = ft_strjoin(t->content, (temp = ft_itoa(shell->exit_code)));
        free(temp);
        t->type = DOLLAR;
        return i + 1;
    }
    if (ft_isdigit(input[i]))
    {
        t->type = DOLLAR;
        return i + 1;
    }
    if (is_breaking_character(input[i]) || input[i] == '\0')
    {
        t->content = ft_strjoin(t->content, "$");
        t->type = DOLLAR;
        return i;
    }
    while (input[i] && !is_breaking_character(input[i]))
    {
        temp = ft_strndup(input + 1, i);
        if (contain_key(shell->env, temp) && !ft_isalnum(input[i + 1]))
        {
            t->content = ft_strjoin(t->content, get_value_by_key(shell->env, (temp)));
            free(temp);
            return i + 1;
        }
        free(temp);
        i++;
    }
    return i + 1;
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

int is_breaking_character(char c)
{
	char breaking_characters[] = "\'\"<>|$ \n\t";

	int size = sizeof breaking_characters / sizeof *breaking_characters - 1;
	for (int i = 0; i < size; i++)
	{
		if (c == breaking_characters[i])
			return 1;
	}
	return 0;
}