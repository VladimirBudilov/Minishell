#include "../../includes/minishell.h"


void create_pipe_list(t_shell *shell)
{
    int index;
    int prev_index;
    int pipe_count;
    int last_pipe;
    t_parser_token **parser_tokens;

    index = 0;
    last_pipe = 0;
    prev_index = 0;
    pipe_count = 0;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;

    while (index < shell->parser_tokens_array->size)
    {
        if(parser_tokens[index]->main_type == PIPELINE)
        {
            last_pipe = index;
            last_pipe++;
            add_command(shell, index, prev_index);
            prev_index = index++;
            pipe_count++;
            continue;
        }
        index++;
    }
    add_last_command(shell, last_pipe);
    ((t_pipe *)shell->pipe_array->array[shell->pipe_array->size - 1])->last_pipe = 1;
}

void execute_pipes(t_shell *shell) {

    int i;
    int fd_array[1000][2];
    //int status;
    t_pipe **pipes;

    i = 0;
    pipes = (t_pipe **) shell->pipe_array->array;
    while (i < shell->pipe_array->size)
    {
        pipe(fd_array[i]);
        execute_pipe(pipes[i], fd_array, i);
        i++;
    }
    i = 0;
    /*while (i < shell->pipe_array->size)
    {
        wait(&status);
        i++;
    }*/

}

void execute_pipe(t_pipe *pipe_token, int array[1000][2], int i) {

   /* pid = fork();
    if (pid == 0) {
        *//*if (pipe_token->first_pipe) {
            dup2(array[i][1], STDOUT_FILENO);
        } else if (pipe_token->middle_pipe) {
            dup2(array[i-1][0], STDIN_FILENO);
            dup2(array[i][1], STDOUT_FILENO);
        } else if (pipe_token->last_pipe) {
            dup2(array[i][0], STDIN_FILENO);
        }
        close(array[i][1]);
        close(array[i][0]);*/
        (void) array;
        (void) i;
        execute_command_in_pipe(pipe_token);
        //execute_command_in_pipe(pipe_token);
        //exit(0);
}

