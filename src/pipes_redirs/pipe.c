#include "../../includes/minishell.h"


void create_pipe_list(t_shell *shell)
{
    int index;
    int prev_index;
    int last_pipe;
    t_parser_token **parser_tokens;

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
    //((t_pipe *)shell->pipe_array->array[shell->pipe_array->size - 1])->last_pipe = 1;
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
        execute_pipe(pipes[i], fd_array, i);
        i++;
    }
    while (wait(NULL) != -1);
}

void execute_pipe(t_pipe *pipe_token, int fd_array[1000][2], int i) {

    int pid;
    pid = fork();
    if (pid == 0)
    {
        if(pipe_token->first_pipe)
        {
            dup2(fd_array[i][1], 1);
            close(fd_array[i][1]);
            close(fd_array[i][0]);
        } else if(pipe_token->middle_pipe)
        {
            dup2(fd_array[i - 1][0], 0);
            dup2(fd_array[i][1], 1);
            close(fd_array[i-1][0]);
            close(fd_array[i-1][1]);
        }
        else if(pipe_token->last_pipe)
        {
            dup2(fd_array[i - 1][0], 0);
            close(fd_array[i - 1][0]);
            close(fd_array[i - 1][1]);

            char baf[1000];
            int res_read = read(0, baf, 1000);
            baf[res_read] = '\0';
            write(1, baf, res_read);
            printf("res_read = %d\n", res_read);
        }
        execute_command_in_pipe(pipe_token);
        exit(0);
    }
}

