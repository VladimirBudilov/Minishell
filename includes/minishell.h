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
#include "ArrayList.h"
#include <limits.h>




void signal_handler(int signal);

void command_func(t_shell *minishell);
void echo_func(t_parser_token **token_key, int size);
void env_func(t_hashmap **hashmap_key, t_parser_token **token_key, int size);
void cd_func(t_hashmap **hashmap_key, t_parser_token **token_key, int size);
void pwd_func(void);
void exit_func(t_parser_token **token_key, int size);
void export_func(t_hashmap **hashmap_key, t_parser_token **token_key, int size, t_shell *minishell);

#endif