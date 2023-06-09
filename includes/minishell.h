#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_token
{
    char *token;
    struct s_token *next;
}   t_token;

typedef struct s_info
{
    char *input;
    char **cmd;
} t_info;


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