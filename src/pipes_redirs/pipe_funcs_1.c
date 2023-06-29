#include "../../includes/minishell.h"

void add_last_command(t_shell *shell, int index) {

    t_parser_token **parser_tokens;
    t_pipe *pipe;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;
    pipe = init_pipe(shell);
    pipe->last_pipe = 1;
    if(parser_tokens[index]->main_type == NEW_SPACE)
        index++;
    while (index < shell->parser_tokens_array->size)
    {
        add_element(pipe->commands, parser_tokens[index]);
        add_flags(pipe, parser_tokens[index]);
        index++;
    }
    add_element(shell->pipe_array, pipe);
}

void add_command(t_shell *shell, int index, int prev) {
    t_parser_token **parser_tokens;
    t_pipe *pipe;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;
    pipe = init_pipe(shell);
    if(prev == 0) {
        pipe->first_pipe = 1;
    }
    else
        pipe->middle_pipe = 1;
    if(parser_tokens[prev]->main_type == NEW_SPACE)
        prev++;
    while (prev < index)
    {
        add_element(pipe->commands, parser_tokens[prev]);
        add_flags(pipe, parser_tokens[prev]);
        prev++;
    }
    if(parser_tokens[prev-1]->main_type == NEW_SPACE)
        delete_element(pipe->commands, pipe->commands->size - 1);
    add_element(shell->pipe_array, pipe);
}