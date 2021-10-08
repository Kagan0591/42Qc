/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:10:05 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/24 09:10:07 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	size_t	s_lenght;

	s_lenght = ft_strlen(s1) + 1;
	mem = malloc(s_lenght);
	if (!mem)
		return (0);
	ft_strlcpy(mem, s1, s_lenght);
	return (mem);
}
