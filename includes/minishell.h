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



// ================= UTILS LISTS TOKENS ===============

// ================= SIGNAL ====================


void	signal_handler(int signal);

// =================BIULT IN FUNC =====================

void command_func(t_shell *minishell);
void echo_func(t_token *arr);
// void cd_func(t_token **token);


#endif