#include "../../includes/minishell.h"

//проверить по тесткейсам
//зафришить

void exit_func(t_parser_token **token_key, t_shell *shell)
{
    ft_putstr_fd("exit\n", 1);
    if (shell->parser_tokens_array->size > 2)
    {
        ft_putstr_fd("minishell: exit: ", 2);
        ft_putstr_fd(token_key[2]->content, 2);
        ft_putstr_fd(": numeric argument required\n", 2);
    }
    exit(1);
}