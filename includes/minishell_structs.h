#ifndef MINI_MINISHELL_STRUCTS_H
#define MINI_MINISHELL_STRUCTS_H

#define MAX_PATH 4096

#include "minishell.h"
#include "ArrayList.h"

typedef struct s_minishell
{
    ArrayList *env;
    ArrayList *tokens_array;
    ArrayList *arguments_array;
    char **from_readline;
    char *input;
    char **cmd;

	int			error_status;
}				t_shell;

#endif //MINI_MINISHELL_STRUCTS_H
