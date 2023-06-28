#include "../../includes/minishell.h"

void find_redir(t_array_list *parser_tokens, t_shell *shell);

void parse_tokens(t_shell *shell)
{
	t_lexer_token **lexer_tokens;
	t_array_list *parser_tokens;
	int size;

	lexer_tokens = (t_lexer_token **) shell->lexer_tokens_array->array;
	parser_tokens = shell->parser_tokens_array;
	size = shell->lexer_tokens_array->size;
	if (size == 0)
		return;
	create_parser_tokens(lexer_tokens, parser_tokens, size);
	find_build_in(parser_tokens);
	find_execver(parser_tokens, shell);
	find_dirs(parser_tokens);
    find_redir(parser_tokens, shell);
	//validate_tokens(parser_tokens);
}

void find_redir(t_array_list *parser_tokens, t_shell *shell) {
    int i;
    int size;
    t_parser_token **array;

    i = 0;
    size = parser_tokens->size;
    array = (t_parser_token **) parser_tokens->array;
    while (i < size) {
        if (array[i]->main_type == REDIRECT_OUTPUT)
        {
            if(array[i + 1]->main_type == NEW_SPACE)
                delete_element(parser_tokens, i + 1);
            array[i]->file = ft_strdup(array[i + 1]->content);
            delete_element(parser_tokens, i + 1);
        }
        else if(array[i]->main_type == REDIRECT_APPEND_OUTPUT) {
            if (array[i + 1]->main_type == NEW_SPACE)
                delete_element(parser_tokens, i + 1);
            array[i]->file = ft_strdup(array[i + 1]->content);
            delete_element(parser_tokens, i + 1);
        }
        else if(array[i]->main_type == REDIRECT_INPUT)
        {
            if (array[i + 1]->main_type == NEW_SPACE)
                delete_element(parser_tokens, i + 1);
            array[i]->file = ft_strdup(array[i + 1]->content);
            delete_element(parser_tokens, i + 1);
        }
        else if(array[i]->main_type == HEREDOC)
        {
            shell->has_here_doc = 1;
            if (array[i + 1]->main_type == NEW_SPACE)
                delete_element(parser_tokens, i + 1);
            array[i]->file = ft_strdup(array[i + 1]->content);
            delete_element(parser_tokens, i + 1);
        }
        i++;
    }
}



















