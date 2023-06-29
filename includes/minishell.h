#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell_structs.h"
#include "minishell_funk.h"
#include "parser_structs.h"
#include "parser_funk.h"
#include <assert.h>
#include <string.h>
#include "array_list.h"
#include <sys/stat.h>
#include <limits.h>
#include "pipe_funcs.h"
#include "pipe_structs.h"
#include "fcntl.h"
#include "redirect_func.h"
#include "validation_funcs.h"

int err_no;

void signal_handler(int signal);
void command_func(t_shell *shell, char **envp);
void echo_func(t_array_list *line);
void env_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell);
void cd_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell);
void pwd_func(void);
void exit_func(t_array_list *line, t_shell *shell);
void export_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell);
void unset_func(t_hashmap **hashmap_key, t_array_list *line, t_shell *shell);
void ex_func(t_array_list *line, t_shell *shell, char **envp);
int check_valid_arguments(t_parser_token **token_key, t_shell *shell);
void free_arr(char **arr);

#endif