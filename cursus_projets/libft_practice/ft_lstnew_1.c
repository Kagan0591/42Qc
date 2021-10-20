t_list *ft_lstnew(void *content)
{
	t_list	*new_elememt;

	new_element = malloc(sizeof(t_list));
	if (new_element)
	{
		new_element->content = content;
		new_element->next = 0;
	}
	return (new_element);
}
