#include "../includes/minishell_structs.h"


int main(int argc, char **argv, char **envp)
{
	(void )argv;
	t_shell *minishell;
	if (argc > 1)
		exit(1);
    minishell = create_shell();
	welcome_message();
    minishell->env = add_env(minishell, envp);
    print_env_from_arraylist(minishell->env);
}


