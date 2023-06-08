#include "../../includes/minishell.h"
 
void echo_func(t_token **token)
{
    t_token *tmp;

    tmp = *token;
    tmp = tmp->next;
    while(tmp)
    {
        printf("%s", tmp->token);
        if(tmp->next != NULL)
            printf(" ");
        tmp = tmp->next;
    }
    printf("\n");
}