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

void echo_func(t_token **token)
{
    //надо решить вопрос с << >> < >
    
    t_token *tmp;
    int check_n;

    check_n = 0;
    tmp = *token;
    tmp = tmp->next;
    if (!(ft_strncmp(tmp->data, "-n", 2)))
    {
        check_n = 1;
        tmp = tmp->next;
    }
    while(tmp)
    {
        print_echo(tmp->data);
        if(tmp->next != NULL)
            write(1, " ", 1);
        tmp = tmp->next;
    }
    if (!check_n)
        write(1, "\n", 1);
}