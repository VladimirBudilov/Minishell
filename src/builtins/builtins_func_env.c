#include "../../includes/minishell.h"

void env_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell)
{
    int i;
	int index;

    i = 0;
	index = 2;
	t_parser_token **token_key;
	token_key = (t_parser_token **)line->array;
    if (line->size > 2)
    {
		if (token_key[index]->main_type == NEW_SPACE)
			index++;
        if (token_key[index]->content[0] != '-')
        {
            ft_putstr_fd("env: ", 2);
            ft_putstr_fd(token_key[2]->content, 2);
            ft_putstr_fd(": No such file or directory\n", 2);
        }
        else
        {
            ft_putstr_fd("env: illegal option -- ", 2);
            ft_putchar_fd(token_key[index]->content[1], 2);
            write(1, "\n", 1);
            ft_putstr_fd("usage: env [-iv] [-P utilpath] [-S string] [-u name]\n", 2);
            ft_putstr_fd("           [name=value ...] [utility [argument ...]]\n", 2);
        }
        return ;
    }
    while(i < shell->env->size)
    {
        if (hashmap_key[i]->value != NULL)
        {
            ft_putstr_fd(hashmap_key[i]->key, 1);
            write(1, "=", 1);
            ft_putstr_fd(hashmap_key[i]->value, 1);
            write(1, "\n", 1);
        }
        i++;
    }
}