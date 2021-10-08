/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:11:01 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/24 09:11:03 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*je dois trouver l'occurence et revoyer len nombre de
charactère dans une chaine cree avec malloc. Elle aura
la grandeur de l occurrence a copier*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i_src;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i_src = 0;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (0);
	while (s[i_src] != '\0')
	{
		if (i_src == start)
			ft_strlcpy(dst, &s[i_src], (len + 1));
		i_src++;
	}
	return (dst);
}
