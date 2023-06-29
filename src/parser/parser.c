#include <stdbool.h>
#include "../../includes/minishell.h"


void syntax_error(t_shell *shell);

void parse_tokens(t_shell *shell)
{
	t_lexer_token **lexer_tokens;
	t_array_list *parser_tokens;
	int size;

	lexer_tokens = (t_lexer_token **) shell->lexer_tokens_array->array;
	parser_tokens = shell->parser_tokens_array;
	size = shell->lexer_tokens_array->size;
	if (shell->cant_execute || (size == 1 && lexer_tokens[0]->type == WHITE_SPACE))
    {
        shell->cant_execute = 1;
        return;
    }
	create_parser_tokens(lexer_tokens, parser_tokens, size);
	find_build_in(parser_tokens);
	find_execver(parser_tokens, shell);
	find_dirs(parser_tokens);
    validate_tokens(parser_tokens, shell);
    find_redir(parser_tokens, shell);
}

void validate_tokens(t_array_list *parser_tokens, t_shell *shell)
{
    int i;
    int j;
    t_parser_token **array;

    i = 0;
    array = (t_parser_token **) parser_tokens->array;
    if(parser_tokens->size == 1 && array[i]->main_type == NEW_SPACE) {
        shell->cant_execute = 1;
        return ;
    }
    else if(array[parser_tokens->size - 1]->main_type == PIPELINE) {
        syntax_error(shell);
        return ;

    }
    else if(is_redir(array[parser_tokens->size - 1])) {
        syntax_error(shell);
        return ;
    }
    i = 0;
    j = 1;
    while(i < parser_tokens->size - 1) {
        if(array[i+1]->main_type == NEW_SPACE)
            j++;
        if(is_redir(array[i]) && is_redir(array[i + 1])) {
            syntax_error(shell);
            return ;
        }
        i++;
    }
    i = 0;
    j = 1;
    while(i < parser_tokens->size - 1) {
        if(array[i+1]->main_type == NEW_SPACE)
            j++;
        if(is_redir(array[i]) && array[i + 1]->main_type == PIPELINE) {
            syntax_error(shell);
            return ;
        }
        i++;
    }
}

void find_redir(t_array_list *parser_tokens, t_shell *shell) {
    int i;
    int size;
    t_parser_token **array;

    if(shell->cant_execute)
        return ;
    i = 0;
    size = parser_tokens->size;
    array = (t_parser_token **) parser_tokens->array;
    while (i < size) {
        if (array[i]->main_type == REDIRECT_OUTPUT)
        {
            if(redir_error(array, i, shell))
                return ;
            if(array[i + 1]->main_type == NEW_SPACE)
                delete_parse_element(parser_tokens, i + 1);
            array[i]->file = array[i + 1]->content;
            delete_parse_element(parser_tokens, i + 1);
        }
        else if(array[i]->main_type == REDIRECT_APPEND_OUTPUT) {
            if(redir_error(array, i, shell))
                return ;
            if (array[i + 1]->main_type == NEW_SPACE)
                delete_parse_element(parser_tokens, i + 1);
            array[i]->file = array[i + 1]->content;
            delete_parse_element(parser_tokens, i + 1);
        }
        else if(array[i]->main_type == REDIRECT_INPUT)
        {
            if(redir_error(array, i, shell))
                return ;
            if (array[i + 1]->main_type == NEW_SPACE)
                delete_parse_element(parser_tokens, i + 1);
            array[i]->file = array[i + 1]->content;
            delete_parse_element(parser_tokens, i + 1);
        }
        else if(array[i]->main_type == HEREDOC)
        {
            if(redir_error(array, i, shell))
                return ;
            shell->has_here_doc = 1;
            if (array[i + 1]->main_type == NEW_SPACE)
                delete_parse_element(parser_tokens, i + 1);
            array[i]->file = array[i + 1]->content;
            delete_parse_element(parser_tokens, i + 1);
        }
        i++;
    }
}

void delete_parse_element(t_array_list *parser_tokens, int i) {
    t_parser_token **array;

    array = (t_parser_token **) parser_tokens->array;
    free(array[i]->content);
    free(array[i]);
    delete_element(parser_tokens, i);

}

int redir_error(t_parser_token **parser_tokens, int i, t_shell *shell) {
    if(parser_tokens[i + 1]->main_type == NEW_SPACE)
        i++;
    if(is_redir(parser_tokens[i + 1]))
    {
        syntax_error(shell);
        return (1);
    }
    return (0);
}

void syntax_error(t_shell *shell) {

    printf("shell: syntax error near unexpected token\n");
    shell->cant_execute = 1;
    err_no = 258;

}



















