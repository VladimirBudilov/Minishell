//
// Created by Vladimir Budilov on 6/7/23.
//

#ifndef MINI_MINISHELL_FUNK_H
#define MINI_MINISHELL_FUNK_H

#include "minishell_structs.h"
#include "ArrayList.h"

typedef struct s_minishell	t_shell;

t_shell *create_shell();

void welcome_message();

void print_env(char **envp);

ArrayList *add_env(t_shell *minishell, char **envp);


#endif //MINI_MINISHELL_FUNK_H
