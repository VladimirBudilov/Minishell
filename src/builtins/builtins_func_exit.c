#include "../../includes/minishell.h"

//проверить по тесткейсам
//зафришить

int check_number_arg(t_parser_token **token_key, t_shell *shell)
{
	int i;
	int j;

	i = 2;
	while(i < shell->parser_tokens_array->size)
	{
		if (token_key[i]->main_type != NEW_SPACE)
		{
			j = 0;
			while(token_key[i]->content[j])
			{
				if(token_key[i]->content[j] == '-' && j == 0)
					j++;
				if(token_key[i]->content[j] == '+' && j == 0)
					j++;
				if (ft_isdigit(token_key[i]->content[j]) == 0)
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}


void exit_func(t_array_list *line, t_shell *shell)
{
	t_parser_token **token_key;
	token_key = (t_parser_token **)line->array;

	int index;
	index = 2;
	if (check_number_arg(token_key, shell))
	{
		if (line->size <= 4) {
			ft_putstr_fd("exit\n", 1);
			exit(1);
		}
		else
		{
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			shell->exit_code = 1;
		}
	}
	else
	{
		if (token_key[index]->main_type == NEW_SPACE)
			index++;
		ft_putstr_fd("exit\n", 1);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(token_key[index]->content, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(1);
	}
}