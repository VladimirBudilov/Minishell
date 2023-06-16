#ifndef MINI_PARSER_FUNK_H
#define MINI_PARSER_FUNK_H

#include "minishell.h"

void get_line(t_shell *minishell);
void parse_readline(t_shell *minishell);
void tokenize(t_shell *shell);
void parse_tokens(t_shell *shell);


/*PARSER*/
t_parser_token *create_token(enum parser_type type, char *content);
void join_words(t_lexer_token *lexer_token, t_parser_token *token);
void open_quotes(t_lexer_token **lexer_tokens, ArrayList *parser_tokens, int *i, int size);
int is_joinable(enum lexer_type type);

/*TOKENIZER*/
t_tokenizer_output * tokenize_greater(char *input);
t_tokenizer_output * tokenize_pipe(char *input);
t_tokenizer_output * tokenize_less(char *input);t_tokenizer_output *tokenize_single_quote(char *input);
t_tokenizer_output *tokenize_double_quote(char *input, t_shell *shell);
t_tokenizer_output *tokenize_dollar(char *input, t_shell *shell);
t_tokenizer_output * tokenize_bare_word(char *input);
t_tokenizer_output * tokenize_white_space(char *input);

/*UTILS*/
char *open_dollar(char *input, t_shell *shell, t_lexer_token *t);
char *ft_strndup(char *str, int n);
char *add_token(t_shell *shell, struct tokenizer_output *po);
int is_breaking_character(char c);

/*ERROR_HANDLER*/
void error(char *message);
void bug(char *message);


#endif //MINI_PARSER_FUNK_H
