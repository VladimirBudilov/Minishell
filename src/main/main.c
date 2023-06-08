#include "../../includes/minishell.h"


int main() 
{
    t_info info;
    t_token *token;

    rl_catch_signals = 0;
    while (1)
    {
        signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);

        info.input = readline("$> ");
        
        if(!info.input)
        {
            printf("exit\n");
            break;
        }
        else
        {
            int i = 0;
            info.for_built_in = ft_split(info.input, ' ');
            while(info.for_built_in[i])
            {
                ft_lstadd_back_token(&token, ft_lstnew_token(info.for_built_in[i]));
                i++;
            }
            if (!ft_strncmp(info.for_built_in[0], "echo", 4))
            {
                echo_func(&token);
                ft_lstclear_token(&token, (*del_token));
            }
        }

    }
    return 0;
}