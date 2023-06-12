#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell_structs.h"
#include "minishell_funk.h"
#include "minishell_parser.h"
#include <assert.h>
#include <string.h>


typedef enum e_token
{
    ft_echo,
    ft_command,
    ft_argument,
    ft_redirection,
    ft_pipe,
    ft_semicolon,
    ft_space,
    ft_dollar,
    ft_quote,
    ft_double_quote,
    ft_backslash,
    ft_newline,
    ft_eof,
    ft_error

}  e_type;

// ================= UTILS LISTS TOKENS ===============

void    read_list_token(t_token **list);
t_token	*ft_lstnew_token(char *token);
void	del_token(char *content);
t_token	*ft_lstlast_token(t_token *lst);
void	ft_lstadd_back_token(t_token **lst, t_token *new);
void	ft_lstdelone_token(t_token *lst, void (*del)(char *));
void	ft_lstclear_token(t_token **lst, void (*del)(char *));
// ================= SIGNAL ====================


void	signal_handler(int signal);
void echo_func(t_token **token);

#endif