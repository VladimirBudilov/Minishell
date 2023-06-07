#include "../includes/minishell_structs.h"


t_hashmap *add_shell_env(t_hashmap *hashmap, char *string, char *cwd);

int main(int argc, char **argv, char **envp)
{
	(void )argv;
	t_minishell *minishell;
	minishell = create_minishell(minishell);
	if (argc > 1)
		exit(1);
	welcome_message();
	printf("%s\n", envp[0]);
}

void welcome_message()
{
	printf("Welcome to Minishell!\n");
	printf("Type 'exit' to quit the program.\n");
	printf("Type 'pwd' to see the current working directory.\n");
	printf("Type 'cd' to change the current working directory.\n");
	printf("Type 'echo' to print a string.\n");
	printf("Type 'env' to see the current environment variables.\n");
}

t_minishell *create_minishell()
{
	t_minishell *minishell;
	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	if (!minishell)
		return (NULL);
	minishell->env = add_shell_env(minishell->env, "PWD", getcwd(NULL, 0));
	return minishell;
}

t_hashmap *add_shell_env(t_hashmap *hashmap, char *string, char *cwd)
{
	t_hashmap *new_hashmap;
	new_hashmap = (t_hashmap *)malloc(sizeof(t_hashmap));
	if (!new_hashmap)
		return (NULL);
	new_hashmap->key = string;
	new_hashmap->value = cwd;
	return new_hashmap;
}
