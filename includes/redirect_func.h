
#ifndef MINI_REDIRECT_FUNC_H
#define MINI_REDIRECT_FUNC_H

#include "minishell.h"
void redir_out_func(t_array_list *parser_tokens, int i);
void redir_out_append_func(t_array_list *parser_tokens, int i);
void redir_in_func(t_array_list *parser_tokens, int i);
void redir_heredoc(t_array_list *parser_tokens, int i);
char *gen_random_name(void);

#endif //MINI_REDIRECT_FUNC_H
