#include "../../includes/minishell_structs.h"

void welcome_message()
{
    ft_putstr_fd("Welcome to Minishell!\n", 1);
    ft_putstr_fd("Type 'exit' to quit the program.\n", 1);
    ft_putstr_fd("Type 'pwd' to see the current working directory.\n", 1);
    ft_putstr_fd("Type 'cd' to change the current working directory.\n", 1);
    ft_putstr_fd("Type 'echo' to print a string.\n", 1);
    ft_putstr_fd("Type 'env' to see the current environment variables.\n", 1);
}

t_shell *create_shell()
{
    t_shell *minishell;

    minishell = (t_shell *)malloc(sizeof(t_shell));
    if (!minishell)
        return (NULL);
    minishell->env = NULL;
	minishell->input = NULL;
    minishell->number_of_pipes = 0;
    minishell->cant_execute = 0;
    minishell->envp = NULL;
    minishell->only_here_doc = 0;
	minishell->lexer_tokens_array = create_array_list();
	minishell->parser_tokens_array = create_array_list();
	minishell->tokenizer_array = create_array_list();
    minishell->pipe_array = create_array_list();
    return minishell;

}
