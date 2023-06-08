#include "../../includes/minishell.h"

void read_list_token(t_token **list)
{
    t_token *tmp;

    tmp = *list;
    while(tmp)
    {
        printf("%s\n", tmp->token);
        tmp = tmp->next;
    }
}

t_token	*ft_lstnew_token(char *token)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
	{
		return (0);
	}
	new->token = token;
	new->next = NULL;
	return (new);
}

void	del_token(char *content)
{
	char *a;

	a = content;
	a = NULL;
}

t_token	*ft_lstlast_token(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*a;

	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		a = ft_lstlast_token(*lst);
		a->next = new;
	}
}

void	ft_lstdelone_token(t_token *lst, void (*del)(char *))
{
	if (!lst)
		return ;
	(*del)(lst->token);
	free(lst);
}


void	ft_lstclear_token(t_token **lst, void (*del)(char *))
{
	t_token	*i;
	t_token	*j;

	i = *lst;
	while (i)
	{
		j = i->next;
		ft_lstdelone_token(i, (*del));
		i = j;
	}
	*lst = 0;
}
