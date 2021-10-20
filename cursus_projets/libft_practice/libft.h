#ifndef __LIBFT_H__
 #define __LIBFT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_list
{
	void *content;
	struct t_list *next;
}t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **alst, t_list *new);

#endif
