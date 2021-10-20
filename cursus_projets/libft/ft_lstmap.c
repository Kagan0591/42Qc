/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:36:19 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/19 17:02:10 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Itère sur la liste lst et applique la fonction f au contenu de chaque élément.
 * Crée une nouvelle liste résultant des applications successives de f. la
 * fonction del est la pour detruire le contenu d un element si necessaire
 *
 * Prototypes
 * #1. L’adresse du pointeur vers un élément.
 * #2. L’adresse de la fonction à appliquer.
 *
 * case si pas lst ou funciton f
 * case si
 *
 * */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;

	if (!lst || !f)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	new_element = new_lst;
	while (lst)
	{
		lst = lst->next;
		if (!new_element)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_element);
	}

	return (new_element);
}


/*
int	main(void)
{
	t_list	*my_list;
	t_list	*my_second_list;

	char	str1[] = "GROSSS!";
	char	str2[] = "On en a";
	char	str3[] = "Sir! Sir!";
	char	str4[] = "HOOO!";

	my_list = ft_lstnew(void *content);
	printf("Valeur de my_list\n\n");
	ft_lstadd_front(&new_element, ft_lstnew((void *)str2));
	ft_lstadd_front(&new_element, ft_lstnew((void *)str3));
	ft_lstadd_front(&new_element, ft_lstnew((void *)str3));
	while (new_element->next != NULL)
	{
		new_element = new_element->next;
		printf("%s\n", new_element->content);
	}
	my_second_list = ft_lstmap(my_list, void *(*f)(void *), void (*del)(void *));


}
*/
