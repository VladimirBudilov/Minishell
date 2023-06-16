#include "../../includes/minishell.h"

//зафришить

void exit_func(t_token **token_key, int size)
{
    ft_putstr_fd("exit\n", 1);
    if (size >= 2)
    {
        ft_putstr_fd("minishell: exit: ", 2);
        ft_putstr_fd(token_key[2]->content, 2);
        ft_putstr_fd(": numeric argument required\n", 2);
    }
    exit(1);
}