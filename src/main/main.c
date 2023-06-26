#include "../../includes/minishell.h"


void pipe_array_cheker(t_shell *shell);

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
        if(has_pipes(minishell)) {
            create_pipe_list(minishell);
            execute_pipes(minishell);
        }
        else
            command_func(minishell, envp);
        clean_array(minishell);

    }
    return 0;
    clean_all(minishell);
}





