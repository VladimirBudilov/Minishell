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
#include "parser_structs.h"
#include "parser_funk.h"
#include <assert.h>
#include <string.h>
#include "ArrayList.h"

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

// =================BIULT IN FUNC =====================

void echo_func(t_token **token);
void cd_func(t_token **token);


#endif