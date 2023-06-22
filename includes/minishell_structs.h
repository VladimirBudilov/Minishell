#ifndef MINI_MINISHELL_STRUCTS_H
#define MINI_MINISHELL_STRUCTS_H

#include "minishell.h"
#include "ArrayList.h"


typedef struct s_minishell
{
    ArrayList *env;
    ArrayList *lexer_tokens_array;
    ArrayList *parser_tokens_array;
	ArrayList *tokenizer_array;
	ArrayList *pipe_array;
	int number_of_pipes;
	int number_of_commands;
    char **from_readline;
    char *input;
    char **cmd;
    int exit_code;

	int			error_status;
}				t_shell;

#endif //MINI_MINISHELL_STRUCTS_H
