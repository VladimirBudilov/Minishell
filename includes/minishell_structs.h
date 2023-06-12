#ifndef MINI_MINISHELL_STRUCTS_H
#define MINI_MINISHELL_STRUCTS_H

#define MAX_PATH 4096

#include "minishell_funk.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_token
{
    enum e_type *type;
    int flag;
    char *data;
    struct s_token *next;
}   t_token;

typedef struct s_minishell
{
    ArrayList *env;
    ArrayList *tokens_array;
    ArrayList *arguments_array;
    char **from_readline;
    t_token *tokens;
    char *input;
    char **cmd;

	int			error_status;
}				t_shell;

typedef struct s_token t_token;

#endif //MINI_MINISHELL_STRUCTS_H
