#include "../../includes/minishell.h"


void redir_out_append_func(t_array_list *parser_tokens, int i);

void redir_in_func(t_array_list *parser_tokens, int i);

void command_func(t_shell *shell, char **envp)
{
    int i;
    int pid;
    i = 0;
    t_parser_token **token_key;
    t_array_list *parser_tokens;

    parser_tokens = shell->parser_tokens_array;
    if (shell->input == NULL)
        return ;
    while(((t_parser_token *)shell->parser_tokens_array->array[i])->main_type == NEW_SPACE)
        i++;
    token_key = (t_parser_token **)shell->parser_tokens_array->array;
    if(has_redir(shell->parser_tokens_array)) {
        pid = fork();
        if (pid == 0) {
            execute_redir(parser_tokens);
            if (token_key[i]->main_type == BIlD_IN)
                execute_builtin(parser_tokens, shell, i);
            else if (token_key[i]->main_type == EXECUTABLE || token_key[0]->main_type == EXECUTABLE_PATH)
                ex_func(parser_tokens, shell, envp);
            exit(0);
        }
        waitpid(pid, NULL, 0);
        return ;
    }
    if(token_key[i]->main_type == BIlD_IN)
        execute_builtin(parser_tokens, shell, i);
    else if (token_key[i]->main_type == EXECUTABLE || token_key[i]->main_type == EXECUTABLE_PATH)
        ex_func(parser_tokens, shell, envp);
    else
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i]->content, 2);
        ft_putstr_fd(": command not found\n", 2);
        return ;
    }
}

void execute_redir(t_array_list *parser_array) {

    t_parser_token **token_key;
    int i;

    i = 0;
    token_key = (t_parser_token **)parser_array->array;
    while(i < parser_array->size)
    {
        if(token_key[i]->main_type == REDIRECT_OUTPUT)
            redir_out_func(parser_array, i);
        else if(token_key[i]->main_type == REDIRECT_APPEND_OUTPUT)
            redir_out_append_func(parser_array, i);
        else if(token_key[i]->main_type == REDIRECT_OUTPUT)
            redir_in_func(parser_array, i);

        /*else if(token_key[i]->main_type == HEREDOC)
            heredoc_func(token_key, shell, i);*/
        i++;
    }
}

void redir_in_func(t_array_list *parser_tokens, int i) {
    int fd;
    t_parser_token **token_key;

    token_key = (t_parser_token **)parser_tokens->array;
    fd = open(token_key[i]->file, O_RDONLY);
    printf("file < = %s\n", token_key[i]->file);
    if (fd < 0)
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i + 1]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return ;
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
}

void redir_out_append_func(t_array_list *parser_tokens, int i) {
    int fd;
    t_parser_token **token_key;

    token_key = (t_parser_token **)parser_tokens->array;
    fd = open(token_key[i]->file, O_WRONLY | O_CREAT | O_APPEND, 0777);
    printf("file >> = %s\n", token_key[i]->file);
    if (fd < 0)
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i + 1]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

void redir_out_func(t_array_list *parser_tokens, int i) {
    int fd;
    t_parser_token **token_key;

    token_key = (t_parser_token **)parser_tokens->array;
    fd = open(token_key[i]->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    printf("file > = %s\n", token_key[i]->file);
    if (fd < 0)
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i + 1]->content, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    //delete_element(parser_tokens, i);
}

int has_redir(t_array_list *tokens) {
    int i;

    i = 0;
    while(i < tokens->size)
    {

        if(is_redir(((t_parser_token **)tokens->array)[i]))
            return (1);
        i++;
    }
    return (0);
}


void execute_builtin(t_array_list *token_array, t_shell *shell, int i) {

    t_hashmap **hashmap_key;
	t_parser_token **token_key;
	token_key = (t_parser_token **)token_array->array;
    hashmap_key = (t_hashmap **)shell->env->array;
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
