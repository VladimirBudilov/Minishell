#ifndef MINI_MINISHELL_STRUCTS_H
#define MINI_MINISHELL_STRUCTS_H

#include "minishell.h"
#include "ArrayList.h"


typedef struct s_minishell
{
    ArrayList *env;
    ArrayList *tokens_array;
    ArrayList *args_array;
    char **from_readline;
    char *input;
    char **cmd;
    int exit_code;

	int			error_status;
}				t_shell;

#endif //MINI_MINISHELL_STRUCTS_H
