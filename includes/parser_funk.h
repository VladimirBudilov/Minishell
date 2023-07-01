#ifndef MINI_PARSER_FUNK_H
#define MINI_PARSER_FUNK_H

# include "minishell.h"
void			get_line(t_shell *minishell);
void			parse_readline(t_shell *minishell);
void			tokenize(t_shell *shell);
void			parse_tokens(t_shell *shell);
t_parser_token	*create_token(enum parser_type type, char *content);
void			join_words(t_lexer_token *lexer_token, t_parser_token *token);
void			open_quotes(t_lexer_token **lexer_tokens, t_array_list *parser_tokens, int *i, int size);
int				is_joinable(enum lexer_type type);
void find_build_in(t_array_list *parser_tokens);
void find_execver(t_array_list *parser_tokens_array, t_shell *shell);
void validate_tokens(t_array_list *parser_tokens, t_shell *shell);
void create_parser_tokens(t_lexer_token **lexer_tokens, t_array_list *parser_tokens, int size);
char * ft_str_to_lower(char *content);
void add_echo(t_parser_token *token, t_array_list *tokens_array, int index);
void add_cd(t_parser_token *token);
void add_pwd(t_parser_token *token);
void add_exprt(t_parser_token *token);
void add_unset(t_parser_token *token);
void add_envp(t_parser_token *token);
void add_exit(t_parser_token *token);
int get_array_size(char **string);
int is_directory(char *path);
void parse_execver_from_path(t_parser_token **parser_tokens, t_shell *shell);
void find_dirs(t_array_list *parser_tokens);
void add_execver_from_path(t_parser_token **parser_tokens, char **paths, int *i, int *j);
void add_execvere(t_parser_token **parser_tokens, t_shell *shell);
void	clean_flags_n(t_array_list *tokens_array, int index);
int					is_flag(const char *content);
void add_redirection(t_lexer_token **lexer_tokens, t_array_list *parser_tokens, int i);



/*TOKENIZER*/
t_tokenizer_output	*tokenize_greater(char *input, t_shell *);
t_tokenizer_output *tokenize_pipe(char *input, t_shell *shell);
t_tokenizer_output *tokenize_less(char *input, t_shell *shell);
t_tokenizer_output *tokenize_single_quote(char *input, t_shell *shell);
t_tokenizer_output *tokenize_double_quote(char *input, t_shell *shell);
t_tokenizer_output *tokenize_dollar(char *input, t_shell *shell);
t_tokenizer_output *tokenize_bare_word(char *input, t_shell *shell);
t_tokenizer_output *tokenize_white_space(char *input, t_shell *shell);
void add_parser_token(t_array_list *tokens_array, enum parser_type type, const char *content);
int is_lexer_redir(enum lexer_type type);
char *tokenize_brackets(char *input, t_shell *shell, t_tokenizer_output **po_array, int *i);
char * tokenize_less_bigger(char *input, t_shell *shell, t_tokenizer_output **po_array, int *i);
char *tokenize_pipe_and_dollar(char *input, t_shell *shell, t_tokenizer_output **po_array, int *i);


/*UTILS*/
int open_dollar(char *input, t_shell *shell, t_lexer_token *t);
char *ft_strndup(char *str, int n);
char *add_token(t_shell *shell, struct tokenizer_output *po);
void free_array(char **paths);
int is_breaking_character(char c);

/*ERROR_HANDLER*/
void error(char *message);
void	syntax_error(t_shell *shell);


#endif
