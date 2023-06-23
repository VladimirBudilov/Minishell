#include "../../includes/minishell.h"

int has_pipes(t_shell *shell)
{
    int i;
    t_parser_token **parser_tokens;

    i = 0;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;
    count_pipes(shell);
    while (i < shell->parser_tokens_array->size)
    {
        if(parser_tokens[i]->main_type == PIPELINE)
            return 1;
        i++;
    }
    return 0;
}

void count_pipes(t_shell *shell) {
    int i;
    t_parser_token **parser_tokens;

    i = 0;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;
    while (i < shell->parser_tokens_array->size)
    {
        if(parser_tokens[i]->main_type == PIPELINE)
            shell->number_of_pipes++;
        i++;
    }
}

int is_redir(t_parser_token *token) {
    if(token->main_type == REDIRECT_APPEND_OUTPUT || token->main_type == REDIRECT_OUTPUT
       || token->main_type == REDIRECT_INPUT || token->main_type == HEREDOC)
        return (1);
    return (0);
}
