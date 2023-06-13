#include "../../includes/minishell.h"

void clean_array(t_shell *minishell);

int main(int argc, char **argv, char **envp)
{
    (void) argv;
    (void) envp;
    t_shell *minishell;

    if (argc > 1)
        exit(1);
    minishell = create_shell();
    welcome_message();
    minishell->env = add_env(envp);
	rl_catch_signals = 0;

    while (1)
    {
		parse_readline(minishell);
        print_all_tokens_arraylist(minishell->tokens_array);
        clean_array(minishell);

    }
    return 0;
}

void clean_array(t_shell *minishell) {
    minishell->tokens_array->size = 0;
}
