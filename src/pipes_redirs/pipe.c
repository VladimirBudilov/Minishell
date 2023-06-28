#include "../../includes/minishell.h"


void create_pipe_list(t_shell *shell)
{
    int index;
    int prev_index;
    int last_pipe;
    t_parser_token **parser_tokens;

    if(shell->number_of_pipes > 250) {
        printf("fork: Resource temporarily unavailable\n");
        return;
    }
    index = 0;
    last_pipe = 0;
    prev_index = 0;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;

    while (index < shell->parser_tokens_array->size)
    {
        if(parser_tokens[index]->main_type == PIPELINE)
        {
            last_pipe = index;
            last_pipe++;
            add_command(shell, index, prev_index);
            index++;
            prev_index = index;
            continue;
        }
        index++;
    }
    add_last_command(shell, last_pipe);
}

void execute_pipes(t_shell *shell) {

    int i;
    int fd_array[1000][2];
    t_pipe **pipes;

    i = 0;
    pipes = (t_pipe **) shell->pipe_array->array;
    while (i < shell->pipe_array->size)
    {
        pipe(fd_array[i]);
        i++;
    }
    i = 0;
    while (i < shell->pipe_array->size)
    {
        if(shell->cant_execute)
            break;
        execute_pipe(pipes[i], i, fd_array);
        i++;
    }
    i = 0;
    while (i < shell->pipe_array->size)
    {
        close(fd_array[i][0]);
        close(fd_array[i][1]);
        i++;
    }
    while (wait(NULL) != -1);
}

void execute_pipe(t_pipe *pipe_token, int i, int fd_array[1000][2]) {

    int pid;
    pid = fork();
    if (pid == 0)
    {
        if(pipe_token->first_pipe)
            dup2(fd_array[i][1], STDOUT_FILENO);
        else if(pipe_token->middle_pipe)
        {
            dup2(fd_array[i - 1][0], STDIN_FILENO);
            dup2(fd_array[i][1], STDOUT_FILENO);
        }
        else if(pipe_token->last_pipe)
            dup2(fd_array[i - 1][0], STDIN_FILENO);

        int j = 0;
        while (j < i) {
            close(fd_array[j][0]);
            close(fd_array[j][1]);
            j++;
        }
        execute_command_in_pipe(pipe_token);
        exit(0);
    }
}

