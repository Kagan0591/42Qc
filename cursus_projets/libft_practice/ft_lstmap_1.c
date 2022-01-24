#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	new_list;
	t_list_new_element;

	new_element = ft_lstnew(lst->content);
	new_list = new_element;
	if (lst || f)
	{
		while (lst)
		{

			lst = lst->next;

		}
		ft_lstadd_back(&new_list, new_element)
	}
}
