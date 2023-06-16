#include "../../includes/minishell.h"

void clean_array(t_shell *minishell);

void print_all_args(ArrayList *list);

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
        command_func(minishell);
        print_all_args(minishell->args_array);
        clean_array(minishell);

    }
    return 0;
}

void print_all_args(ArrayList *list) {
    int i;
    i = 0;
    while (i < list->size) {
        //printf("%d\n", ((int) ((t_parser_output *) list->array[i])->main_type));
        printf("%s", ((t_parser_output *) list->array[i])->content);
        i++;
    }
    printf("\n");
}

void clean_array(t_shell *minishell) {
    minishell->tokens_array->size = 0;
    minishell->args_array->size = 0;
}
