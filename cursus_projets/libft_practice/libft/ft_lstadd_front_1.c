/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:09:09 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/21 09:57:09 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst || new)
	{
		new->next = *alst;
		*alst = new;
	}
}
/*
int	main(void)
{
	t_list	*my_list;

	my_list = ft_lstnew((char *) "bonjour");
	ft_lstadd_front(&my_list, ft_lstnew((char *) "comment sa va ?"));
	while (my_list != NULL)
	{
		printf("%s\n", my_list->content);
		my_list = my_list->next;
	}
	return (0);
}
*/
