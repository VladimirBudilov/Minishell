#include "../../includes/minishell.h"


void command_func(t_shell *minishell)
{

    int size;
    t_token **token_key;

    size = minishell->tokens_array->size;
    token_key = (t_token **)minishell->tokens_array->array;
    // printf("string = %s\n", ((t_token *)minishell->tokens_array->array[0])->content);
    // printf("token string = %s\n", token_key[0]->content);
    if (!(ft_strncmp(token_key[0]->content, "echo", 4)))
        echo_func(token_key, size);
    else if(!(ft_strncmp(token_key[0]->content, "cd", 2)))
        cd_func(token_key, size);
}