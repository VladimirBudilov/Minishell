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
            pipe_array_cheker(minishell);
        }
        else
            command_func(minishell, envp);
        print_all_pipe(minishell->pipe_array);
        clean_array(minishell);

    }
    return 0;
    clean_all(minishell);
}

void pipe_array_cheker(t_shell *shell) {

    int i = 0;
    int j = 0;
    t_pipe **pipes;
    pipes = (t_pipe **) shell->pipe_array->array;
    while(i < shell->pipe_array->size) {
        if(pipes[i]->first_pipe == 1) {
            j = 0;
            printf("first_pipe\n");
            while(j < pipes[i]->commands->size) {
                printf("first_pipe command %s\n", ((t_parser_token *)pipes[i]->commands->array[j])->content);
                j++;
            }
        }
        else if(pipes[i]->last_pipe == 1) {
            j = 0;
            printf("last_pipe\n");
            while(j < pipes[i]->commands->size) {
                printf("last_pipe command %s\n", ((t_parser_token *)pipes[i]->commands->array[j])->content);
                j++;
            }
        }
        else if (pipes[i]->middle_pipe == 1){
            j = 0;
            printf("middle_pipe\n");
            while(j < pipes[i]->commands->size) {
                printf("middle_pipe command %s\n", ((t_parser_token *)pipes[i]->commands->array[j])->content);
                j++;
            }
        }
        i++;
    }

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
            printf("command  %s   ",((t_parser_token *)pipes[i]->commands->array[j])->content);
            j++;
        }
        printf("\n\n");
        i++;
    }
}


