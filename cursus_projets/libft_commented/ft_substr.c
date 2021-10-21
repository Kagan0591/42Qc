/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:11:01 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/21 13:53:04 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* je dois trouver l'occurence et revoyer len nombre de
 * charactère dans une chaine cree avec malloc. Elle aura
 * la grandeur de l occurrence a copier*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = (ft_strlen(s) - start);
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, ((char *)s + start), (len + 1));
	return (dst);
}
