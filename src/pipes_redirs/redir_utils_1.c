#include "../../includes/minishell.h"


char	*gen_random_name(void)
{
char			buff[4];
char			*name;
int				fd;
int				nbr;

name = ft_calloc(1, sizeof(char));
fd = open("/dev/urandom", O_RDONLY);
if (fd < -1)
return ("ERROR");
read(fd, buff, 4);
nbr = *(int *)buff;
if (nbr < 0)
nbr++;
if (nbr < 0)
nbr = nbr * (-1);
*name = ('a' + nbr % 26);
return (name);
}


int has_redir(t_array_list *tokens) {
    int i;

    i = 0;
    while(i < tokens->size)
    {
        if(is_redir(((t_parser_token **)tokens->array)[i]))
            return (1);
        i++;
    }
    return (0);
}