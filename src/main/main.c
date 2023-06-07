#include "../../includes/minishell.h"

int main() 
{
    char *input;
    rl_catch_signals = 0;
    while (1)
    {
        signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
        input = readline("$> ");
        if(!input)
        {
            printf("exit\n");
            break;
        }
    }
    return 0;
}
