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


void exit_func(t_parser_token **token_key, t_shell *shell)
{
	if (check_number_arg(token_key, shell))
	{
		if (shell->parser_tokens_array->size <= 4) {
			ft_putstr_fd("exit\n", 1);
			shell->exit_code = ft_atoi(token_key[2]->content);
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
		ft_putstr_fd("exit\n", 1);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(token_key[2]->content, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(1);
	}
}