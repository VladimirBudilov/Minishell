
#ifndef MINI_REDIRECT_FUNC_H
#define MINI_REDIRECT_FUNC_H

#include "minishell.h"
int redir_out_func(t_array_list *parser_tokens, int i);
int redir_out_append_func(t_array_list *parser_tokens, int i);
int redir_in_func(t_array_list *parser_tokens, int i);
int redir_heredoc(t_array_list *parser_tokens, int i, t_shell *shell);
void find_redir(t_array_list *parser_tokens, t_shell *shell);
int redir_error(t_parser_token **parser_tokens, int i, t_shell *shell);
void delete_parse_element(t_array_list *parser_tokens, int i);
void execute_heredoc(int i, char *delimiter);
void free_redirects(t_shell *shell);

#endif //MINI_REDIRECT_FUNC_H
