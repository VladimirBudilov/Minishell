#include "../../includes/minishell.h"

void add_cd(t_parser_token *token)
{
	if (ft_strcmp(ft_str_to_lower(token->content), "cd") == 0)
	{
		token->main_type = BIlD_IN;
		token->sub_type = CD;
	}
}

void add_echo(t_parser_token *token)
{

	if (ft_strcmp(ft_str_to_lower(token->content), "echo") == 0)
	{
		token->main_type = BIlD_IN;
		token->sub_type = ECHO;
	}
}



