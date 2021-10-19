/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:33:55 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/19 10:55:18 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*first_element;

	if (alst || new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			first_element = ft_lstlast(*alst);
			first_element->next = new;
		}
	}
}
