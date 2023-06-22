#ifndef MINI_PIPE_STRUCTS_H
#define MINI_PIPE_STRUCTS_H

# include "minishell.h"

typedef struct s_pipe
{
    ArrayList *commands;
    int *fd_in;
    int *fd_out;
    int first;
    int middle;
    int last;
    int num_of_pipe;
    int num_of_commands;
    int *pid;
    int *status;

} t_pipe;

typedef struct s_redirection
{


} t_redirection;


#endif //MINI_PIPE_STRUCTS_H
