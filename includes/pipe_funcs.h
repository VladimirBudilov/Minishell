#ifndef MINI_PIPE_FUNCS_H
#define MINI_PIPE_FUNCS_H


#include "minishell.h"
#include "pipe_structs.h"


void count_pipes(t_shell *shell);
void add_command(t_shell *shell, int index, int prev);
void add_last_command(t_shell *shell, int index);
int has_pipes(t_shell *shell);
void create_pipe_list(t_shell *shell);
void execute_pipes(t_shell *shell);
void execute_command_in_pipe(t_pipe *pipe);
void execute_builtin_in_pipe(t_pipe *pipe);
void execute_execve_in_pipe(t_pipe *pipe);
void execute_redir_in_pipe(t_pipe *pipe);
void add_flags(t_pipe *pipe, t_parser_token *token);
int is_redir(t_parser_token *token);
void execute_pipe(t_pipe *pipe_token, int fd_array[1000][2], int i);
t_pipe * init_pipe(t_shell *shell);
void clean_pipe_commands(t_shell *shell);



#endif //MINI_PIPE_FUNCS_H
