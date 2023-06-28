#include "../../includes/minishell.h"

void execute_command_in_pipe(t_pipe *pipe) {
    int pid;
    int i;
    t_parser_token **token_key;

    i = 0;
    token_key = (t_parser_token **)pipe->commands->array;

    while(token_key[i]->main_type == NEW_SPACE)
        i++;
    if(has_redir(pipe->shell->parser_tokens_array)) {
        pid = fork();
        if (pid == 0) {
            execute_redir(pipe->commands);
            if (token_key[i]->main_type == BIlD_IN)
                execute_builtin_in_pipe(pipe);
            else if (token_key[i]->main_type == EXECUTABLE || token_key[i]->main_type == EXECUTABLE_PATH)
                execute_execve_in_pipe(pipe);
            else
            {
                if(pipe->shell->has_here_doc)
                    exit(0);
                ft_putstr_fd("shell last: ", 2);
                ft_putstr_fd(token_key[i]->content, 2);
                ft_putstr_fd(": command not found\n", 2);
                exit(0);
            }
            exit(0);
        }
        waitpid(pid, NULL, 0);
        return ;
    }
    if(pipe->is_builtin)
        execute_builtin_in_pipe(pipe);
    else if(pipe->is_execve)
        execute_execve_in_pipe(pipe);
    else
    {
        ft_putstr_fd("shell last: ", 2);
        ft_putstr_fd(token_key[i]->content, 2);
        ft_putstr_fd(": command not found\n", 2);
        exit(0);
    }
}

void execute_execve_in_pipe(t_pipe *pipe) {
    t_array_list *token_key;
    token_key = (t_array_list *)pipe->commands;
    ex_func(token_key, pipe->shell, (char **)pipe->shell->env->array);
}

void execute_builtin_in_pipe(t_pipe *pipe)
{
    int i;
    t_parser_token **token_key;
	t_array_list *token_array;
    t_hashmap **hashmap_key;
    t_shell *shell;

    i = 0;
    shell = pipe->shell;
    hashmap_key = (t_hashmap **) shell->env->array;
    token_key = (t_parser_token **) pipe->commands->array;
	token_array = pipe->commands;
    while(token_key[i] == NEW_SPACE)
        i++;
    if (token_key[i]->sub_type == ECHO)
        echo_func(token_array);
    else if (token_key[i]->sub_type == ENVP)
        env_func(hashmap_key, token_array, shell);
    else if (token_key[i]->sub_type == CD)
        cd_func(hashmap_key, token_array, shell);
    else if (token_key[i]->sub_type == PWD)
        pwd_func();
    else if (token_key[i]->sub_type == EXIT)
        exit_func(token_array, shell);
    else if (token_key[i]->sub_type == EXPORT)
        export_func(hashmap_key, token_array, shell);
    else if (token_key[i]->sub_type == UNSET)
        unset_func(hashmap_key, token_array, shell);
}