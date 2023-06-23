#include "../../includes/minishell.h"

void execute_command_in_pipe(t_pipe *pipe) {

    if(pipe->is_builtin)
        execute_builtin_in_pipe(pipe);
/*    else if(pipe->is_execve)
        execute_execve_in_pipe(pipe);
    else if(pipe->is_redir)
        execute_redir_in_pipe(pipe);*/

}

/*
void execute_redir_in_pipe(t_pipe *pipe) {

}

void execute_execve_in_pipe(t_pipe *pipe) {

}
*/

void execute_builtin_in_pipe(t_pipe *pipe)
{
    int i;
    t_parser_token **token_key;
    t_hashmap **hashmap_key;
    t_shell *shell;

    i = 0;
    shell = pipe->shell;
    hashmap_key = (t_hashmap **) shell->env->array;
    token_key = (t_parser_token **) pipe->commands->array;
    while(token_key[i] == NEW_SPACE)
        i++;
    if (token_key[i]->sub_type == ECHO)
        echo_func(token_key, shell);
    else if (token_key[i]->sub_type == ENVP)
        env_func(hashmap_key, token_key, shell);
    else if (token_key[i]->sub_type == CD)
        cd_func(hashmap_key, token_key, shell);
    else if (token_key[i]->sub_type == PWD)
        pwd_func();
    else if (token_key[i]->sub_type == EXIT)
        exit_func(token_key, shell);
    else if (token_key[i]->sub_type == EXPORT)
        export_func(hashmap_key, token_key, shell);
    else if (token_key[i]->sub_type == UNSET)
        unset_func(hashmap_key, token_key, shell);
}