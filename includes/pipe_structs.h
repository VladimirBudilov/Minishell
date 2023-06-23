#ifndef MINI_PIPE_STRUCTS_H
#define MINI_PIPE_STRUCTS_H

# include "minishell.h"

typedef struct s_pipe
{
    t_array_list *commands;
    int *fd_in;
    int *fd_out;
    int first;
    int middle;
    int last;
    int *pid;
    int *status;
    int is_execve;
    int is_builtin;
    int is_redir;
} t_pipe;

typedef struct s_redirection
{


} t_redirection;


#endif //MINI_PIPE_STRUCTS_H
