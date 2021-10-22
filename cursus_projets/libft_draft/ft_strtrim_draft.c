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

/* lAlloue (avec malloc(3)) et retourne une copie de
la chaine ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaine de
caractères
*/

/* 11111bonjour11111 
set = 1
donc
la chaine retourne est bonjour

1 trouver les char depuis la fin

2 trouver les char depuis le debut

3 copier la chaine s1 dans s2 a partir de l<emplacement ou l occurence de debut commence 
  jusqua la position de loccurence de fin


*/ 

#include "libft.h"
// Je veux la position de la derniere occurence au debut, si il n'y en a pas, break la boucle et retourn i
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
	return (i); // Le nombre de char qui a ete skip au debut
}
// Je veux la position de la derniere occurence a la fin, si il n'y en a pas, break la boucle et retourn i
static int	ft_getend(const char *s, const char *set)
{
	size_t	i_lenght;
	size_t	i;

	i_lenght = ft_strlen(s) - 1;
	i = 0;
	while (s[i_lenght] > 0)
	{
		if(ft_strchr(set, s[i_lenght]) == 0)
			break ;
		i_lenght--;
		i++;
	}
	return (i); // Le nombre de char qui a ete skip a la fin
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	s_lenght;

	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	i = 0;
	s_lenght = ft_strlen(s1) - start;
	s2 = malloc(sizeof(s1 + 1 - start - end));
	if (!s2)
		return (0);
	while (s1[i + start] != '\0' && (s_lenght - end) > 0)
	{
		s2[i] = s1[i + start];
		i++;
		s_lenght--;
	}
	return (s2);
}

#include <stdio.h>

int	main(void)
{
	char	*str = {"Bonjour"};

	printf("%s\n", ft_strtrim(str, "Bor"));
	return (0);
}
