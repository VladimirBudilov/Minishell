#include "../../includes/minishell.h"
 
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

void echo_func(t_token **token_key, int size)
{

    //надо решить вопрос с << >> < >
    //кавычки
    //проверить в конце перенос строки с кэт е когда подкдючим
    int check_n;
    int i = 2;
    check_n = 0;

    if (!(ft_strncmp(token_key[i]->content, "-n", 2)))
    {
        check_n = 1;
        i++;
    }
    while(i < size)
    {
        print_echo(token_key[i]->content);
        i++;
    }
    if (!check_n)
        write(1, "\n", 1);
}
