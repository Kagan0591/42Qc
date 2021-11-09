/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:09:58 by tchalifo          #+#    #+#             */
/*   Updated: 2021/11/09 13:24:14 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i_s;

	i_s = 0;
	while (s[i_s] != '\0')
		i_s++;
	return (i_s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclenght;

	i = 0;
	srclenght = ft_strlen(src);
	if (dstsize == 0)
		return (srclenght);
	while (src[i] != '\0' && dstsize-- > 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclenght);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	destlenght;
	size_t	srclenght;

	i_dest = 0;
	i_src = 0;
	destlenght = ft_strlen(dst);
	srclenght = ft_strlen((char *)src);
	if (dstsize < destlenght)
		return (dstsize + srclenght);
	while (dst[i_dest])
		i_dest++;
	while (src[i_src] && (i_dest + 1) < dstsize)
	{
		dst[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dst[i_dest] = '\0';
	return (destlenght + srclenght);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char )c)
			return ((char *)s + 1);
		s++;
	}
	return (0);
}
