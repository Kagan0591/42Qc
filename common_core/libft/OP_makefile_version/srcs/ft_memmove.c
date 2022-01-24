/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:56:00 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/21 15:10:02 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	if (d > s)
	{
		while (len-- > 0)
			if (d[len] != s[len])
				d[len] = s[len];
	}
	else
	{
		while (len-- > 0)
		{
			if (*d != *s)
				*d = *s;
			d++;
			s++;
		}
	}
	return (dst);
}
