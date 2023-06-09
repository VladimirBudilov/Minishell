#ifndef MINI_MINISHELL_FUNK_H
#define MINI_MINISHELL_FUNK_H

#include "minishell_structs.h"
#include "ArrayList.h"

typedef struct s_minishell	t_shell;
t_shell *create_shell();
void welcome_message();
void print_env(char **envp);
ArrayList *add_env(char **envp);
void parse_readline(t_shell *minishell);
void get_line(t_shell *minishell);
void add_tokens(t_shell *minishell);
void parse_readline(t_shell *minishell);

#endif //MINI_MINISHELL_FUNK_H
