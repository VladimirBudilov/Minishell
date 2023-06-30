#include "../../includes/minishell.h"

void execute_pipes(t_shell *shell) {

    int i;
    int fd_array[1000][2];
    t_pipe **pipes;

    i = 0;
    pipes = (t_pipe **) shell->pipe_array->array;
    while (i < shell->pipe_array->size - 1)
    {

        printf("pipe %d\n", i);
        pipe(fd_array[i]);
        i++;
    }
    i = 0;
    while (i < shell->pipe_array->size)
    {
        execute_pipe(pipes[i], i, fd_array);
        i++;
    }
    i = 0;
    while (i < shell->pipe_array->size - 1)
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
    if(pid == -1)
        error(strerror(err_no));
    if (pid == 0)
    {
        if(pipe_token->first_pipe) {
            dup2(fd_array[i][1], STDOUT_FILENO);
            close(fd_array[i][1]);
        }
        else if(pipe_token->middle_pipe)
        {
            dup2(fd_array[i - 1][0], STDIN_FILENO);
            dup2(fd_array[i][1], STDOUT_FILENO);
            close(fd_array[i - 1][0]);
            close(fd_array[i][1]);
        }
        else if(pipe_token->last_pipe) {
            dup2(fd_array[i - 1][0], STDIN_FILENO);
            close(fd_array[i - 1][0]);

            char buf[1001];
            int n;
            ft_putstr_fd("heredoc> 1\n", 2);
            n = read(STDIN_FILENO, buf, 1000);
            ft_putstr_fd("heredoc> 2\n", 2);

            buf[n] = '\0';
            ft_putnbr_fd(n, 2);

        }
        /*int j = 0;
        while (j < i)
        {
            close(fd_array[j][0]);
            close(fd_array[j][1]);
            j++;
        }*/
        execute_command_in_pipe(pipe_token);
        exit(0);
    }
}