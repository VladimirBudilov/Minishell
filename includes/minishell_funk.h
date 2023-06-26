#ifndef MINI_MINISHELL_FUNK_H
#define MINI_MINISHELL_FUNK_H

#include "minishell.h"
#include "ArrayList.h"
#include "parser_structs.h"

typedef struct s_arrayList t_array_list;
typedef struct s_minishell	t_shell;
t_shell *create_shell();
void welcome_message();
void print_env(char **envp);
t_array_list *add_env(char **envp);
void add_tokens(t_shell *minishell);
void clean_array(t_shell *minishell);
void print_all_args(t_array_list *list);
void free_tokenizer_output_array(t_array_list *tokens);
int ft_is_ascii(char *str);
void free_parser_tokens(t_array_list *tokens);
void execute_builtin(t_array_list *token_array, t_shell *shell, int i);
int has_redir(t_array_list *tokens);
void execute_redir(t_array_list *tokens, t_shell *shell);
void clean_all(t_shell *shell);
void free_env(t_array_list *tokens);

#endif //MINI_MINISHELL_FUNK_H
