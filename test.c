#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *command, char **envp) {
    char *argv[] = {command, NULL};
    execve(command, argv, envp);
    perror("execve");
    exit(EXIT_FAILURE);
}

void pipe_func(t_parser_token **token_key, t_shell *shell, char **envp) {
    int pipefd[2];
    pid_t pid;
    int status;

    // Создание pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return;
    }

    // Создание дочернего процесса
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    }

    if (pid == 0) {
        // Дочерний процесс

        // Закрытие конца pipe, связанного с чтением
        close(pipefd[0]);

        // Перенаправление стандартного вывода в конец pipe, связанный с записью
        dup2(pipefd[1], STDOUT_FILENO);

        // Запуск первой команды
        execute_command(token_key[0]->content, envp);
    } else {
        // Родительский процесс

        // Закрытие конца pipe, связанного с записью
        close(pipefd[1]);

        // Перенаправление стандартного ввода в конец pipe, связанный с чтением
        dup2(pipefd[0], STDIN_FILENO);

        // Запуск второй команды
        execute_command(token_key[1]->content, envp);

        // Дождаться завершения дочернего процесса
        waitpid(pid, &status, 0);
    }
}