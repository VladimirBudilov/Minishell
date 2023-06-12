#include "../../includes/minishell_structs.h"

void welcome_message()
{
    printf("Welcome to Minishell!\n");
    printf("Type 'exit' to quit the program.\n");
    printf("Type 'pwd' to see the current working directory.\n");
    printf("Type 'cd' to change the current working directory.\n");
    printf("Type 'echo' to print a string.\n");
    printf("Type 'env' to see the current environment variables.\n");
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
	minishell->arguments_array = createArrayList();
    return minishell;
}
