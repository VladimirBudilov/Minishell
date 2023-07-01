#ifndef MINI_VALIDATION_FUNCS_H
#define MINI_VALIDATION_FUNCS_H

#include "minishell.h"

int has_only_new_space(t_array_list *parser_tokens);
int ends_with_pipeline(t_array_list *parser_tokens);
int ends_with_redir(t_array_list *parser_tokens);
int has_consecutive_redirs(t_array_list *parser_tokens);
int has_redir_before_pipeline(t_array_list *parser_tokens);
void handle_cant_execute(t_shell *shell);
void handle_syntax_error(t_shell *shell);
void remove_parse_element(t_array_list *parser_tokens, int index);
void remove_new_space(t_array_list *parser_tokens, int index);
void handle_redirect(t_parser_token **array, int index, t_array_list *parser_tokens, t_shell *shell);
void	remove_new_space(t_array_list *parser_tokens, int index);
void print_2d_arr(char **pString);


#endif //MINI_VALIDATION_FUNCS_H
