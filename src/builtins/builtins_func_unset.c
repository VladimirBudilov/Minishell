#include "../../includes/minishell.h"

int get_position_of_element(t_hashmap **hashmap_key, char *key, t_shell *shell)
{
    int i;

    i = 0;
    while(i < shell->env->size)
    {
        if (!ft_strncmp(hashmap_key[i]->key, key, ft_strlen(key)))
        {
            return i;
        }
        i++;
    }
    return 0;
}


void unset_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell)
{
    int i;
	t_parser_token **token_key;
    
    i = 2;
	token_key = (t_parser_token **)line->array;
    if (!check_valid_arguments(token_key, shell))
		return ;
    while (i < line->size)
    {
        if (token_key[i]->main_type != NEW_SPACE)
        {
            if(contain_key(shell->env, token_key[i]->content))
            {
                delete_element(shell->env, get_position_of_element(hashmap_key, token_key[i]->content, shell));
            }
        }
        i++;
    }
	err_no = 0;
}