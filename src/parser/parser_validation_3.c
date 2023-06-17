#include "../../includes/minishell.h"

void add_exit(t_parser_token *token) {
    if(ft_strcmp(ft_str_to_lower(token->content), "exit") == 0)
    {
        token->main_type = BIlD_IN;
        token->sub_type = EXIT;
    }

}

void add_envp(t_parser_token *token) {
    if(ft_strcmp(ft_str_to_lower(token->content), "envp") == 0)
    {
        token->main_type = BIlD_IN;
        token->sub_type = ENVP;
    }

}

void add_unset(t_parser_token *pParser) {
    if(ft_strcmp(ft_str_to_lower(pParser->content), "unset") == 0)
    {
        pParser->main_type = BIlD_IN;
        pParser->sub_type = UNSET;
    }

}

void add_exprt(t_parser_token *token) {
    if(ft_strcmp(ft_str_to_lower(token->content), "export") == 0)
    {
        token->main_type = BIlD_IN;
        token->sub_type = EXPORT;
    }

}

void add_pwd(t_parser_token *token) {
    if(ft_strcmp(ft_str_to_lower(token->content), "pwd") == 0)
    {
        token->main_type = BIlD_IN;
        token->sub_type = PWD;
    }

}


