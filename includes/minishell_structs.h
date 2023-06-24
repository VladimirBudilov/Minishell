#ifndef MINI_MINISHELL_STRUCTS_H
#define MINI_MINISHELL_STRUCTS_H

#include "minishell.h"
#include "ArrayList.h"


typedef struct s_minishell
{
    t_array_list *env;
    t_array_list *lexer_tokens_array;
    t_array_list *parser_tokens_array;
	t_array_list *tokenizer_array;
	t_array_list *pipe_array;
	int number_of_pipes;
    char *input;
    int exit_code;

	int			error_status;
}				t_shell;

#endif //MINI_MINISHELL_STRUCTS_H
