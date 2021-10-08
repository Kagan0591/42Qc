/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:56:00 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/20 13:56:03 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d > s)
	{
		while (n-- > 0)
			if (d[n] != s[n])
				d[n] = s[n];
	}
	else
	{
		while (n-- > 0)
		{
			if (*d != *s)
				*d = *s;
			d++;
			s++;
		}
	}
	return (dst);
}
