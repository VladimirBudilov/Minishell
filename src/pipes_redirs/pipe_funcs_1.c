#include "../../includes/minishell.h"

void add_last_command(t_shell *shell, int *index) {

    t_parser_token **parser_tokens;
    t_pipe *pipe;

    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;
    pipe = malloc(sizeof(t_pipe));
    add_element(shell->pipe_array, pipe);
    pipe->commands = createArrayList();
    while (*index < shell->parser_tokens_array->size)
    {
        add_element(pipe->commands, parser_tokens[*index]);
        *index = *index + 1;
    }
}

void add_command(t_shell *shell, const int *index, int *prev) {
    t_parser_token **parser_tokens;
    t_pipe *pipe;

    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;
    pipe = malloc(sizeof(t_pipe));
    add_element(shell->pipe_array, pipe);
    pipe->commands = createArrayList();
    while (*prev < *index)
    {
        add_element(pipe->commands, parser_tokens[*prev]);
        *prev = *prev + 1;
    }
}