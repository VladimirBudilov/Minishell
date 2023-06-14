#include "../../includes/minishell.h"

int check_first_start(t_hashmap *hashmap_key)
{
    if (!ft_strncmp(hashmap_key->key, "OLDPWD", 6))
        if (hashmap_key->value == NULL)
            return 1;
    return 0;
}


void env_func(t_hashmap **hashmap_key, t_token **token_key, int size)
{
    int i;

    i = 0;
    if (size > 2)
    {
        if (token_key[2]->content[0] != '-')
        {
            ft_putstr_fd("env: ", 2);
            ft_putstr_fd(token_key[2]->content, 2);
            ft_putstr_fd(": No such file or directory\n", 2);
        }
        else
        {
            ft_putstr_fd("env: illegal option -- ", 2);
            ft_putchar_fd(token_key[2]->content[1], 2);
            write(1, "\n", 1);
        }
        return ;
    }
    while(hashmap_key[i])
    {
        if(!check_first_start(hashmap_key[i]))
        {
            ft_putstr_fd(hashmap_key[i]->key, 1);
            write(1, "=", 1);
            ft_putstr_fd(hashmap_key[i]->value, 1);
            write(1, "\n", 1);
        }
        i++;
    }
}