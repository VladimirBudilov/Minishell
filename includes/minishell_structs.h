#ifndef MINI_MINISHELL_STRUCTS_H
#define MINI_MINISHELL_STRUCTS_H

#define MAX_PATH 4096

#include "minishell_funk.h"
#include "../libs/libft/libft.h"
#include "../libs/get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct t_hashmap
{
	char	*key;
	char	*value;
}				t_hashmap;

typedef struct s_minishell
{
	t_hashmap	*env;
	t_hashmap	*local_vars;
	int			error_status;
}				t_minishell;

typedef struct s_token
{
	char	*content;
	int		type;
}				t_token;




#endif //MINI_MINISHELL_STRUCTS_H
