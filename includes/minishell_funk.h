#ifndef MINI_MINISHELL_FUNK_H
#define MINI_MINISHELL_FUNK_H

#include "minishell.h"
#include "ArrayList.h"

typedef struct s_arrayList ArrayList;
typedef struct s_minishell	t_shell;
t_shell *create_shell();
void welcome_message();
void print_env(char **envp);
ArrayList *add_env(char **envp);
void add_tokens(t_shell *minishell);
void clean_array(t_shell *minishell);
void print_all_args(ArrayList *list);

#endif //MINI_MINISHELL_FUNK_H
