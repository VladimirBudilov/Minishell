#include "../../includes/minishell.h"


void command_func(t_shell *minishell)
{

    int size;
    t_token **token_key;
    t_hashmap **hashmap_key;

    size = minishell->tokens_array->size;
    token_key = (t_token **)minishell->tokens_array->array;
    hashmap_key = (t_hashmap **)minishell->env->array;
    // printf("string = %s\n", ((t_token *)minishell->tokens_array->array[0])->content);

    if (!(ft_strncmp(token_key[0]->content, "echo", 4)))
    {
        //printf("1\n");
        echo_func(token_key, size);
    }
    else if (!(ft_strncmp(token_key[0]->content, "env", 3)))
    {
        //printf("2\n");
        env_func(hashmap_key, token_key, size);
    }
    else if(!(ft_strncmp(token_key[0]->content, "cd", 2)))
    {
        //printf("3\n");
        cd_func(hashmap_key, token_key, size);
    }
    else if(!(ft_strncmp(token_key[0]->content, "pwd", 3)))
    {
        //printf("4\n");
        pwd_func();
    }
    else
        return ;


}