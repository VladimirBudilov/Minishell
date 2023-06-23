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
        if(has_pipes(minishell)) {
            create_pipe_list(minishell);
            execute_pipes(minishell);
        }
        else
        {
            command_func(minishell, envp);
        }
        print_all_pipe(minishell->pipe_array);
        clean_array(minishell);

    }
    return 0;
    clean_all(minishell);
}

void print_all_pipe(t_array_list *pipes_array) {
    int i;
    int j;
    t_pipe **pipes;

    i = 0;
    pipes = (t_pipe **) pipes_array->array;
    while (i < pipes_array->size)
    {
        j = 0;
        printf("new pipe %d\n", i);
        while(j < pipes[i]->commands->size)
        {
            printf("command %d : %s\n", j, ((t_parser_token *)pipes[i]->commands->array[j])->content);
            j++;
        }
        i++;
    }
}
