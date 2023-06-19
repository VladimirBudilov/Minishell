#include "../../includes/minishell.h"

//провечакать тест кейсы
//проверить валидность аргументов
//не записывать повторяющиеся аргументы
//поменять сайзы



void print_command_export(t_hashmap **hashmap_key, t_shell *shell)
{
    int i;

    i = 0;
    
    if (shell->parser_tokens_array->size <= 2)
    {
        while(i < shell->env->size)
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

int check_key(char *str, t_hashmap **hashmap_key, t_shell *shell)
{
    int i;
//	char **tmp;

    i = 0;

//	if(ft_strchr(str, '='))
//	{
//		tmp = ft_split(str, '=');
//	}

    while(i < shell->env->size)
    {
        if(!ft_strncmp(hashmap_key[i]->key, str, ft_strlen(str)))
            return 1;
        i++;
    }
    return 0;
}

void check_double_arguments(t_hashmap **hashmap_key, t_parser_token **token_key, t_shell *shell)
{
    int i;

    i = 2;
    if (shell->parser_tokens_array->size > 2)
    {
        while(i < shell->parser_tokens_array->size)
        {
            if (token_key[i]->main_type != NEW_SPACE)
                if(!check_key(token_key[i]->content, hashmap_key, shell))
                    add_element(shell->env, create_hashmap(token_key[i]->content));
            i++;
        }
    }
}



void export_func(t_hashmap **hashmap_key, t_parser_token **token_key, t_shell *shell)
{
    print_command_export(hashmap_key, shell);
    if(!check_valid_arguments(token_key, shell))
        return ;
    check_double_arguments(hashmap_key, token_key, shell);
}
