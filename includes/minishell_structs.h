#ifndef MINI_MINISHELL_STRUCTS_H
#define MINI_MINISHELL_STRUCTS_H

#define MAX_PATH 4096

#include "minishell_funk.h"
#include "../libs/libft/libft.h"
#include <stdio.h>



typedef struct s_minishell
{
    ArrayList *env;
    char **from_readline;
    ArrayList *tokens;

	int			error_status;
}				t_shell;

typedef struct s_token t_token;

#endif //MINI_MINISHELL_STRUCTS_H
