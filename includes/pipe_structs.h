#ifndef MINI_PIPE_STRUCTS_H
#define MINI_PIPE_STRUCTS_H

# include "minishell.h"

typedef struct s_pipe
{
    t_array_list *commands;

    int first_pipe;
    int middle_pipe;
    int last_pipe;
    int is_execve;
    int is_builtin;
    int is_redir;
	int pid;
    t_shell *shell;
} t_pipe;

typedef struct s_redirection
{

} t_redirection;


#endif //MINI_PIPE_STRUCTS_H
