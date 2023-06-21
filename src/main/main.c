#include "../../includes/minishell.h"

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
		clean_array(minishell);
	}
    clean_all(minishell);
	return 0;
}
