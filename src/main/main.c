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
		//print_all_args(minishell->parser_tokens_array);
        command_func(minishell, envp);
        clean_array(minishell);

    }
    return 0;
    clean_all(minishell);
}
