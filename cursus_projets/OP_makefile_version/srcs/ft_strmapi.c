/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:03:49 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/19 09:03:51 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sptr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	sptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sptr)
		return (0);
	while (s[i])
	{
		sptr[i] = (*f)(i, s[i]);
		i++;
	}
	sptr[i] = '\0';
	return (sptr);
}
