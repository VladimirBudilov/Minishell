#include "../../includes/minishell.h"

    //надо решить вопрос с << >> < >
    //кавычки
    //проверить в конце перенос строки с кэт е когда подкдючим
    //првоерить по тест кейсам 


void print_echo(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] != 34)
            ft_putchar_fd(str[i], 1);
        i++;
    }
}

void echo_func(t_parser_token **token_key, t_shell *shell)
{
    int check_n;
    int i = 2;
    check_n = 0;
    if(shell->parser_tokens_array->size <= 2)
    {
        write(1, "\n", 1);
        return ;
    }
    if (!(ft_strncmp(token_key[i]->content, "-n", 2)) && token_key[i]->content[2] == '\0')
    {
        check_n = 1;
        i++;
    }
    while(i < shell->parser_tokens_array->size)
    {
        print_echo(token_key[i]->content);
        i++;
    }
    if (!check_n)
        write(1, "\n", 1);
}
