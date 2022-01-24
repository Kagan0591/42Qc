#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
/*
void	del(void * element)
{
	char	*str;

	str = element;
	memset(element, 0, strlen(str));
}

int	main(void)
{
	t_list	*my_list;

	my_list = ft_lstnew((char *) "Middle");
	ft_lstadd_front(&my_list, ft_lstnew((char *) "First"));
	ft_lstadd_back(&my_list->next, ft_lstnew((char *) "Last"));
	ft_lstdelone(my_list, my_list->content);
	while (my_list != NULL)
	{
		printf("%s\n", my_list->content);
		my_list = my_list->next;
	}
	return (0);
}
*/
