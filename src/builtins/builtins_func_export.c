#include "../../includes/minishell.h"

//провечакать тест кейсы
//проверить валидность аргументов
//не записывать повторяющиеся аргументы


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

int check_key(char *str, t_hashmap **hashmap_key)
{
    int i;
    
    i = 0;
    while(hashmap_key[i])
    {
        if(!ft_strncmp(hashmap_key[i]->key, str, ft_strlen(str)))
            return 1;
        i++;
    }
    return 0;
}

void check_double_arguments(t_hashmap **hashmap_key, t_parser_token **token_key, int size, t_shell *minishell)
{
    int i;

    i = 2;
    if (size > 2)
    {
        while(token_key[i])
        {
            if (token_key[i]->main_type != NEW_SPACE)
                if(!check_key(token_key[i]->content, hashmap_key))
                {
                    printf("content %s\n", token_key[i]->content);
                    add_element(minishell->env, create_hashmap(token_key[i]->content));
                }
            i++;
        }
    }
}



void export_func(t_hashmap **hashmap_key, t_parser_token **token_key, int size, t_shell *minishell)
{
    print_command_export(hashmap_key, size);
    if(!check_valid_arguments(token_key, size))
        return ;
    check_double_arguments(hashmap_key, token_key, size, minishell);
}
