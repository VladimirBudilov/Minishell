#include "../../includes/minishell.h"

// get_position изменить
//првоерить тест кейсы

int get_position_of_element(t_hashmap **hashmap_key, char *key)
{
    int i;

    i = 0;
    while(hashmap_key[i])
    {
        if (!ft_strncmp(hashmap_key[i]->key, key, ft_strlen(key)))
        {
            return i;
        }
        i++;
    }
    return 0;
}


void unset_func(t_hashmap **hashmap_key, t_parser_token **token_key, int size, t_shell *minishell)
{
    int i;
    
    i = 2;
    (void)hashmap_key;
    (void)size;
    while (i < size)
    {
        if (token_key[i]->main_type != NEW_SPACE)
        {
            
            if(contain_key(minishell->env, token_key[i]->content))
            {
                delete_element(minishell->env, get_position_of_element(hashmap_key, token_key[i]->content));
            }
        }
        i++;
    }
    // printf("size posle %d\n", minishell->env->size);
}