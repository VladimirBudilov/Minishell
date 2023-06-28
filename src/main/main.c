#include "../../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void) argv;
	t_shell *shell;
    err_no = 0;
	if (argc > 1)
		exit(1);
    shell = create_shell();
	welcome_message();
    shell->env = add_env(envp);
	rl_catch_signals = 0;
	while (1)
	{
		parse_readline(shell);
        if(has_pipes(shell))
        {
            create_pipe_list(shell);
            execute_pipes(shell);
        }
        else
            command_func(shell, envp);
        clean_array(shell);
    }
    exit(0);
}





