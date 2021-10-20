/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:05:32 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/20 14:05:57 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst)
	{
		while (lst->next != NULL)
		{
			count++;
			lst = lst->next
		}
	}
	return (count);
}
