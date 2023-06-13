#include "../../includes/minishell.h"
 
void print_echo(void *content)
{
    char *str = (char *)content;
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] != 34)
            ft_putchar_fd(str[i], 1);
        i++;
    }
}

void echo_func(t_token *arr)
{

    //надо решить вопрос с << >> < >
    t_token *tmp;
    int check_n;
    int i = 0;
    check_n = 0;
    tmp = arr;
    
    i++;

    if (!(ft_strncmp((char *)tmp[i].content, "-n", 2)))
    {
        check_n = 1;
        i++;
    }
    while(tmp[i].type != END)
    {
        printf("1\n");
        print_echo(tmp[i].content);
        if(tmp[i + 1].content != NULL)
            write(1, " ", 1);
        i++;
    }
    if (!check_n)
        write(1, "\n", 1);
}
