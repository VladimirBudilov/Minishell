#include "../../includes/minishell.h"

void parse_tokens(char *input, ArrayList *tokens);


void parse_readline(t_shell *minishell)
{
	get_line(minishell);
	add_tokens(minishell);
}

void add_tokens(t_shell *minishell)
{
	ArrayList *tokens;

	tokens = createArrayList();
	parse_tokens(minishell->input, tokens);
}

void parse_tokens(char *input, ArrayList *tokens)
{
	int i;
	int j;
	char *token;

	i = 0;
	j = 0;
	token = (char *)malloc(sizeof(char) * 4096);
	while (input[i])
	{
		if (input[i] == ' ')
		{
			token[j] = '\0';
			add_element(tokens, token);
			token = (char *)malloc(sizeof(char) * 4096);
			j = 0;
		}
		else
		{
			token[j] = input[i];
			j++;
		}
		i++;
	}
	token[j] = '\0';
	add_element(tokens, token);
	i = 0;
	while (i < tokens->size)
	{
		printf("%s\n", tokens->array[i]);
		i++;
	}
}

void get_line(t_shell *minishell)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	minishell->input = readline("$> ");

	if(!minishell->input)
	{
		printf("\033[1A\033[3Cexit\n");
		exit(1);
	}
	else if (*minishell->input == '\0')
		free(minishell->input);
}
