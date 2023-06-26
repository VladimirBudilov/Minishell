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

t_pipe * init_pipe(t_shell *shell) {

    t_pipe *pipe_token;

    pipe_token = malloc(sizeof(t_pipe));
    pipe_token->commands = createArrayList();
    pipe_token->shell = shell;
    pipe_token->first_pipe = 0;
    pipe_token->middle_pipe = 0;
    pipe_token->last_pipe = 0;
    pipe_token->is_redir = 0;
    pipe_token->is_builtin = 0;
    pipe_token->is_execve = 0;
    return pipe_token;
}

void add_flags(t_pipe *pipe, t_parser_token *token) {

    if(pipe->is_redir == 1)
        return;
    if(pipe->is_builtin == 1 || pipe->is_execve == 1 )
        return;
    if(is_redir(token)) {
        pipe->is_redir = 1;
    }
    else if(token->main_type == BIlD_IN) {
        pipe->is_builtin = 1; }
    else if(token->main_type == EXECUTABLE || token->main_type == EXECUTABLE_PATH) {
        pipe->is_execve = 1; }

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
    add_element(shell->pipe_array, pipe);

}