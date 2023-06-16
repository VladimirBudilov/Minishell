#include "../../includes/minishell.h"


void command_func(t_shell *minishell)
{

    int size;
    t_token **token_key;
    t_hashmap **hashmap_key;

    if (minishell->input == NULL)
        return ;

    size = minishell->tokens_array->size;
    token_key = (t_token **)minishell->tokens_array->array;
    hashmap_key = (t_hashmap **)minishell->env->array;
    // printf("string = %s\n", ((t_token *)minishell->tokens_array->array[0])->content);

    if (!(ft_strncmp(token_key[0]->content, "echo", 4)))
        echo_func(token_key, size);
    else if (!(ft_strncmp(token_key[0]->content, "env", 3)))
        env_func(hashmap_key, token_key, size);
    else if(!(ft_strncmp(token_key[0]->content, "cd", 2)))
        cd_func(hashmap_key, token_key, size);
    else if(!(ft_strncmp(token_key[0]->content, "pwd", 3)))
        pwd_func();
    else if(!(ft_strncmp(token_key[0]->content, "exit", 4)))
        exit_func(token_key, size);
    else if(!(ft_strncmp(token_key[0]->content, "export", 4)))
        export_func(hashmap_key, token_key, size);
    else
    {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(token_key[0]->content, 2);
        ft_putstr_fd(": command not found\n", 2);
        return ;
    }


}