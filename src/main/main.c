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
        //print_all_tokens(minishell->lexer_tokens_array);
        print_all_args(minishell->parser_tokens_array);
        clean_array(minishell);

    }
    return 0;
}

void print_all_args(ArrayList *list) {
    int i;
    i = 0;
    while (i < list->size) {
        //printf("%d\n", ((int) ((t_parser_token *) list->array[i])->main_type));
        printf("parser content : %s\n", ((t_parser_token *) list->array[i])->content);
        i++;
    }
    printf("\n");
}

void clean_array(t_shell *minishell) {
    minishell->lexer_tokens_array->size = 0;
    minishell->parser_tokens_array->size = 0;
}
