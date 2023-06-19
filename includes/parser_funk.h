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
void add_white_space(ArrayList *parser_tokens);
void add_input_redirect(ArrayList *parser_tokens);
void add_output_redirect(ArrayList *parser_tokens);
void add_herdoc(ArrayList *parser_tokens);
void add_append_output(ArrayList *parser_tokens);
void add_pipe(ArrayList *parser_tokens);
void find_build_in(ArrayList *parser_tokens);
void find_execver(ArrayList *parser_tokens_array, t_shell *shell);
void validate_tokens(ArrayList *parser_tokens);
void create_parser_tokens(t_lexer_token **lexer_tokens, ArrayList *parser_tokens, int size);
char * ft_str_to_lower(char *content);
void add_echo(t_parser_token *token, ArrayList *tokens_array, int index);
void add_cd(t_parser_token *token);
void add_pwd(t_parser_token *token);
void add_exprt(t_parser_token *token);
void add_unset(t_parser_token *pParser);
void add_envp(t_parser_token *token);
void add_exit(t_parser_token *token);
int get_array_size(char **string);
int is_directory(char *path);
void add_execver(t_parser_token **parser_tokens, char **paths, int size_main, int size_sub);

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
