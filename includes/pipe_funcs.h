#ifndef MINI_PIPE_FUNCS_H
#define MINI_PIPE_FUNCS_H


#include "minishell.h"

void count_pipes(t_shell *shell);
void add_command(t_shell *shell, const int *index, int *prev);
void add_last_command(t_shell *shell, int *index);
int has_pipes(t_shell *shell);
void create_pipe_list(t_shell *shell);
void execute_pipes(t_shell *shell);


#endif //MINI_PIPE_FUNCS_H
