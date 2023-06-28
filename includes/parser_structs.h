#ifndef MINI_PARSER_H
#define MINI_PARSER_H

#include "minishell.h"

enum lexer_type {
	WHITE_SPACE,
	LESS_THAN_LESS_THAN,
	LESS_THAN,
	DOLLAR,
	PIPE,
	GREATER_THAN,
	GREATER_THAN_GREATER_THAN,
	BARE_WORD,
	SINGLE_QUOTES,
	DOUBLE_QUOTES,
};

enum parser_type {
    NEW_SPACE,
    WORDLIST,
	REDIRECT_INPUT,
	REDIRECT_OUTPUT,
	REDIRECT_APPEND_OUTPUT,
    HEREDOC,
    PIPELINE,
    BIlD_IN,
    CD,
    PWD,
    ECHO,
    EXPORT,
    ENVP,
    UNSET,
    EXIT,
    EXECUTABLE,
    EXECUTABLE_PATH,
    DIRECTORY,
};

typedef struct parser {
    enum parser_type main_type;
    enum parser_type sub_type;
    int flags;
    char *content;
    char *file;
} t_parser_token;

typedef struct token {
	enum lexer_type type;
	char *content;
} t_lexer_token;

typedef struct tokenizer_output {
	char *string;
	struct token token;
} t_tokenizer_output;

#endif //MINI_PARSER_H
