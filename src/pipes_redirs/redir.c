#include "../../includes/minishell.h"

void execute_redir(t_array_list *parser_array) {

    t_parser_token **token_key;
    int i;

    i = 0;
    token_key = (t_parser_token **)parser_array->array;
    while(i < parser_array->size)
    {
        if(token_key[i]->main_type == REDIRECT_OUTPUT)
        {
            redir_out_func(parser_array, i);
            continue;
        }
        else if(token_key[i]->main_type == REDIRECT_APPEND_OUTPUT) {
            redir_out_append_func(parser_array, i);
            continue;
        }
        else if(token_key[i]->main_type == REDIRECT_INPUT)
        {
            redir_in_func(parser_array, i);
            continue;
         }
        else if(token_key[i]->main_type == HEREDOC)
        {
            redir_heredoc(parser_array, i);
            continue;
        }
        i++;
    }
}

