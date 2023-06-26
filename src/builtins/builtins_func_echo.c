#include "../../includes/minishell.h"

void echo_func(t_array_list *line)
{
    int check_n;
    int i;

	i = 2;
    check_n = 0;
	t_parser_token **token_key = (t_parser_token **)line->array;
	if (token_key[0]->main_type == NEW_SPACE)
		i++;
    if(line->size <= 2)
    {
        write(1, "\n", 1);
        return ;
    }
    if (!(ft_strncmp(token_key[i]->content, "-n", 2)) && token_key[i]->content[2] == '\0')
    {
        check_n = 1;
        i += 2;
    }
    while(i < line->size)
    {
        ft_putstr_fd(token_key[i]->content, 1);
        i++;
    }
    if (!check_n)
        write(1, "\n", 1);
}
