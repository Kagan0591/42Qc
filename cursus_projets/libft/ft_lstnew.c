#include "libft.h"
#include <stdio.h>

t_list *ft_lstnew(void *content)
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
