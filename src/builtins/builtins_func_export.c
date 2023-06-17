#include "../../includes/minishell.h"

void print_command_export(t_hashmap **hashmap_key, int size)
{
    int i;

    i = 0;
    if (size <= 2)
    {
        while(hashmap_key[i])
        {

            ft_putstr_fd("declare -x ", 1);
            ft_putstr_fd(hashmap_key[i]->key, 1);
            if (hashmap_key[i]->value != NULL)
            {
                write(1, "=\"", 2);
                ft_putstr_fd(hashmap_key[i]->value, 1);
                write(1, "\"", 2);
            }
            write(1, "\n", 1);
            i++;
        }
    }
}

void add_string_to_export(t_hashmap **hashmap_key, t_parser_token **token_key, int size, t_shell *minishell)
{
    int i;
    (void)hashmap_key;
    i = 2;
    if (size > 2)
    {
        while(token_key[i])
        {
            if(token_key[i]->main_type != NEW_SPACE)
                add_element(minishell->env, create_hashmap(token_key[i]->content));
            i++;
        }
    }
}



void export_func(t_hashmap **hashmap_key, t_parser_token **token_key, int size, t_shell *minishell)
{
    print_command_export(hashmap_key, size);
    add_string_to_export(hashmap_key, token_key, size, minishell);
}
