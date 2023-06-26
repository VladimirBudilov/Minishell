#include <stdbool.h>
#include "../../includes/minishell.h"

void command_func(t_shell *shell, char **envp)
{
    int i;

    i = 0;
    t_parser_token **token_key;
	t_array_list *tmp;
    if (shell->input == NULL)
        return ;
    while(((t_parser_token *)shell->parser_tokens_array->array[i])->main_type == NEW_SPACE)
        i++;
    token_key = (t_parser_token **)shell->parser_tokens_array->array;
 	tmp = shell->parser_tokens_array;
    if(token_key[i]->main_type == BIlD_IN)
        execute_builtin(tmp, shell, i);
    else if (token_key[i]->main_type == EXECUTABLE || token_key[i]->main_type == EXECUTABLE_PATH)
        ex_func(tmp, shell, envp);
/*    else if(has_redir(shell->parser_tokens_array))
        execute_redir(token_key, shell, envp);*/
    else
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[i]->content, 2);
        ft_putstr_fd(": command not found\n", 2);
        return ;
    }
}

/*void execute_redir(t_parser_token **tokens, t_shell *shell, char **envp) {

}*/

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
