#ifndef MINI_PARSER_FUNK_H
#define MINI_PARSER_FUNK_H

#include "minishell.h"

void parse_tokens(char *input, ArrayList *tokens);
int is_breaking_character(char c);
t_tokenizer_output * tokenize_white_space(char *input);
void error(char *message);
void bug(char *message);
t_tokenizer_output * tokenize_single_quote(char *input);
t_tokenizer_output * tokenize_double_quote(char *input);
t_tokenizer_output * tokenize_dollar(char *input);
t_tokenizer_output * tokenize_bare_word(char *input);
char *add_token(t_shell *shell, struct tokenizer_output *po);
void tokenize(t_shell *shell);
void parse_readline(t_shell *minishell);
void get_line(t_shell *minishell);
struct tokenizer_output tokenize_greater_greater(char *input);
t_tokenizer_output * tokenize_greater(char *input);
t_tokenizer_output * tokenize_pipe(char *input);
t_tokenizer_output * tokenize_less(char *input);
struct tokenizer_output tokenize_less_less(char *input);
char *ft_strndup(char *str, int n);


#endif //MINI_PARSER_FUNK_H
