#include "../../includes/minishell.h"

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
		printf("1\n");
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

