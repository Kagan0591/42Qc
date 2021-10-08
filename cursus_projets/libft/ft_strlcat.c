/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:54:30 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/20 13:54:32 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	destlenght;
	size_t	srclenght;

	i_dest = 0;
	i_src = 0;
	destlenght = ft_strlen(dest);
	srclenght = ft_strlen(src);
	while (dest[i_dest])
		i_dest++;
	if (n < i_dest)
		return (n + srclenght);
	while (src[i_src] && (i_dest + 1) < n)
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dest[i_dest] = '\0';
	return (destlenght + srclenght);
}
