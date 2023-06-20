#include "../../includes/minishell.h"


void command_func(t_shell *shell, char **envp)
{

    t_parser_token **token_key;
    t_hashmap **hashmap_key;

    if (shell->input == NULL)
        return ;

    token_key = (t_parser_token **)shell->parser_tokens_array->array;
    hashmap_key = (t_hashmap **)shell->env->array;

    if (token_key[0]->sub_type == ECHO)
        echo_func(token_key, shell);
    else if (token_key[0]->sub_type == ENVP)
        env_func(hashmap_key, token_key, shell);
    else if (token_key[0]->sub_type == CD)
        cd_func(hashmap_key, token_key, shell);
    else if (token_key[0]->sub_type == PWD)
        pwd_func();
    else if (token_key[0]->sub_type == EXIT)
        exit_func(token_key, shell);
    else if (token_key[0]->sub_type == EXPORT)
        export_func(hashmap_key, token_key, shell);
    else if (token_key[0]->sub_type == UNSET)
        unset_func(hashmap_key, token_key, shell);
	else if (token_key[0]->main_type == EXECUTABLE)
		ex_func(token_key, shell, envp);
    else
    {
        ft_putstr_fd("shell: ", 2);
        ft_putstr_fd(token_key[0]->content, 2);
        ft_putstr_fd(": command not found\n", 2);
        return ;
    }
}