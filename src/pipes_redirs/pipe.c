#include "../../includes/minishell.h"

void create_pipe_list(t_shell *shell)
{
    int index;
    int prev_index;
    int pipe_count;
    t_parser_token **parser_tokens;

    index = 0;
    prev_index = 0;
    pipe_count = 0;
    parser_tokens = (t_parser_token **) shell->parser_tokens_array->array;

    while (index < shell->parser_tokens_array->size)
    {
        if(parser_tokens[index]->main_type == PIPELINE)
        {
                add_command(shell, &index, &prev_index);
                index++;
                pipe_count++;
                continue;
        }
        if(pipe_count == shell->number_of_pipes) {
            add_last_command(shell, &index);
            index++;
            break;
        }
        index++;
    }
}

void execute_pipes(t_shell *shell) {

    int pid;
    int i;
    int j;
    int fd[2];
    int fd_in;
    int fd_out;
    int status;
    t_pipe **pipes;

    i = 0;
    j = 0;
    pipes = (t_pipe **) shell->pipe_array->array;
    while (i < shell->pipe_array->size)
    {
        if (pipe(fd) == -1)
            exit(1);
        pid = fork();
        if (pid == -1)
            exit(1);
        if (pid == 0)
        {
            if (pipes[i]->first == 1)
            {
                fd_out = fd[1];
                fd_in = 0;
            }
            else if (pipes[i]->middle == 1)
            {
                fd_out = fd[1];
                fd_in = fd[0];
            }
            else if (pipes[i]->last == 1)
            {
                fd_out = 1;
                fd_in = fd[0];
            }
            dup2(fd_in, 0);
            dup2(fd_out, 1);
            close(fd[0]);
            close(fd[1]);
            execute_command_in_pipe(pipes[i]);
        }
        /*else
        {
            if (pipes[i]->first == 1)
                close(fd[1]);
            else if (pipes[i]->middle == 1)
            {
                close(fd[1]);
                close(fd[0]);
            }
            else if (pipes[i]->last == 1)
                close(fd[0]);
        }
        i++;
        j++;*/
    }
    i = 0;
    while (i < shell->pipe_array->size)
    {
        wait(&status);
        i++;
    }

}




