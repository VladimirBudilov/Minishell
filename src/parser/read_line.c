#include "../../includes/minishell.h"

int ft_is_ascii(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(!ft_isascii(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void parse_readline(t_shell *minishell)
{
	get_line(minishell);
	if (minishell->input == NULL)
		return ;
	add_history(minishell->input);
	tokenize(minishell);
    parse_tokens(minishell);
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
	{
		free(minishell->input);
		minishell->input = NULL;
	}
    else if (!ft_is_ascii(minishell->input))
    {
        free(minishell->input);
        minishell->input = NULL;
    }
}
