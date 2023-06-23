#include <stdbool.h>
#include "../../includes/minishell.h"

void add_last_command(t_shell *shell, int *index) {

    t_parser_token **parser_tokens;
    t_pipe *pipe;

    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;
    pipe = malloc(sizeof(t_pipe));
    add_element(shell->pipe_array, pipe);
    pipe->commands = createArrayList();
    pipe->last = 1;
    pipe->shell = shell;
    while (*index < shell->parser_tokens_array->size)
    {
        add_element(pipe->commands, parser_tokens[*index]);
        add_flags(pipe, parser_tokens[*index]);
        *index = *index + 1;
    }
}
void add_flags(t_pipe *pipe, t_parser_token *token) {

    if(is_redir(token))
        pipe->is_redir = 1;
    if(token->main_type == BIlD_IN)
        pipe->is_builtin = 1;
    if(token->main_type == EXECUTABLE)
        pipe->is_execve = 1;
}
void add_command(t_shell *shell, const int *index, int *prev) {
    t_parser_token **parser_tokens;
    t_pipe *pipe;

    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;
    pipe = malloc(sizeof(t_pipe));
    add_element(shell->pipe_array, pipe);
    pipe->commands = createArrayList();
    pipe->shell = shell;
    if(*prev == 0)
        pipe->first = 1;
    else
        pipe->middle = 1;
    while (*prev < *index)
    {
        add_element(pipe->commands, parser_tokens[*prev]);
        add_flags(pipe, parser_tokens[*index]);
        *prev = *prev + 1;
    }
}