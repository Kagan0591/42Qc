/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:54:54 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/20 13:54:56 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (*s)
		s++;
	if (*s + 1 == '\0')
		return ((char *)s + 1);
	while (i-- >= 0)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
