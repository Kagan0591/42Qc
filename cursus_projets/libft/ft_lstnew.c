#include "libft.h"
#include <stdio.h>

t_list  *ft_lstnew(void *content)
{
    t_list  *new_element;
    new_element = malloc(sizeof(t_list));
    if (new_element)
    {
        new_element->content = content;
        new_element->next = 0;
    }
    return (new_element);
}
/*
void    ft_lstadd_front(t_list **alst, t_list *new)
{
    if (alst || new)
    {
        new->next = *alst;
        *alst = new;
    }
}

t_list *ft_lstlast(t_list *lst)
{
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return (lst);
}

int		main(void)
{
	char	str1[] = "lorem ipsum dolor sit";
	char	str2[] = "lorem ipsum dolor sit";

	t_list	*new_element;

	new_element = ft_lstnew((void *)str1);
	printf("\n%s\n", new_element->content);
    new_element->content = str2;
	printf("\n%s\n", new_element->content);
}

*/
