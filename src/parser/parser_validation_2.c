#include "../../includes/minishell.h"

void add_cd(t_parser_token *token) {
    if(ft_strcmp(ft_str_to_lower(token->content), "cd") == 0)
    {
        token->main_type = BIlD_IN;
        token->sub_type = CD;
    }
}

void add_echo(t_parser_token *token) {

    if(ft_strcmp(ft_str_to_lower(token->content), "echo") == 0)
    {
        token->main_type = BIlD_IN;
        token->sub_type = ECHO;
    }
}

char * ft_str_to_lower(char *content) {
    int i;
    char *str;

    str = ft_strdup(content);
    i = 0;
    while (str[i])
    {
        str[i] = ft_tolower(str[i]);
        i++;
    }
    return str;
}

#include "../../includes/minishell.h"

void add_cd(t_parser_token *token) {
    if(ft_strcmp(ft_str_to_lower(token->content), "cd") == 0)
    {
        token->main_type = BIlD_IN;
        token->sub_type = CD;
    }
}

void add_echo(t_parser_token *token) {

    if(ft_strcmp(ft_str_to_lower(token->content), "echo") == 0)
    {
        token->main_type = BIlD_IN;
        token->sub_type = ECHO;
    }
}

struct stat s;
assert(stat("/usr/bin/ls", &s) != -1);

char * ft_str_to_lower(char *content) {
    int i;
    char *str;

    str = ft_strdup(content);
    i = 0;
    while (str[i])
    {
        str[i] = ft_tolower(str[i]);
        i++;
    }
    return str;
}
