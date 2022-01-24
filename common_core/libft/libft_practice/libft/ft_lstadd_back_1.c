/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:37:49 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/21 09:57:17 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_node;

	if (*alst == NULL)
		*alst = new;
	else
	{
		last_node = ft_lstlast(*alst);
		last_node->next = new;
	}
}
/*
int	main(void)
{
	t_list	*my_list;

	my_list = ft_lstnew((char *) "Middle");
	ft_lstadd_front(&my_list, ft_lstnew((char *) "First"));
	ft_lstadd_back(&my_list->next, ft_lstnew((char *) "Last"));
	while (my_list != NULL)
	{
		printf("%s\n", my_list->content);
		my_list = my_list->next;
	}
	return (0);
}
*/
