/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:28:52 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/24 12:28:54 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	ft_getstart(const char *s, const char *set, size_t count)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s[count] == set[j])
			ft_getstart(s, set, count++);
		j++;
	}
	return (count);
}

int	main(void)
{
	printf("%d\n", ft_getstart("   xxx   xxx", " x", 0));
	return (0);
}

/*

static int	ft_getstart(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

*/


/*


static int	ft_getend(const char *s, const char *set)
{
	size_t	i_lenght;
	size_t	i;

	i_lenght = ft_strlen(s) - 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[0] == set[0])
		{
			while (s[i_lenght + i] == set[i] && set[i] != '\0')
				i_lenght--;
				i++;
		}
		printf("GETEND%zu\n", i);
		i++;
	}
	return (i);
}

*/
/*

static int	ft_getend(const char *s, const char *set)
{
	size_t	i_lenght;
	size_t	i;

	i_lenght = ft_strlen(s) - 1;
	i = 0;
	while (s[i_lenght] > 0)
	{
		if (ft_strchr(set, s[i_lenght]) == 0)
			break ;
		i_lenght--;
		i++;
	}
	return (i);
}
*/
/*
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;

	s2 = ft_substr(s1, (unsigned int) ft_getstart(s1, set, 0),\
     (ft_strlen(s1) - (ft_getstart(s1, set, 0))) - ft_getend(s1, set));
	return (s2);
}

#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_strtrim("abcd", "ab"));
}

*/
