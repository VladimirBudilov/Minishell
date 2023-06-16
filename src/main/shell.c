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
	minishell->tokens_array = createArrayList();
	minishell->args_array = createArrayList();
    return minishell;
}
