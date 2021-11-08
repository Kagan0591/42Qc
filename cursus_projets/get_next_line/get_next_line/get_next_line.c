/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:23:55 by tchalifo          #+#    #+#             */
/*   Updated: 2021/11/08 15:56:39 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

char	*get_next_line(fd)
{
	char	*line;
	char	*buffer;
	int		read_output;
	int		count;

	line = NULL; // Pour eviter les junks values
	count = 0;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	read_output = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE + 1] = '\0';
	while (!ft_strchr(buffer, '\n')) // Copie dans le buffer les chars jusqu a ce qu il trouve le /n
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		printf("Buf test = %s\n", buffer);
		if (read_output <= 0) // Si il n y a plus de chars dans le fichier sort de boucle
		{
			count++;
			break;
		}
		line = ft_strjoin(line, buffer);
		printf("line test2 = %s\n", line);
	}
	crop_line(&line);
	printf("count = %d\n", count);
	return (line);
}

/* Verifier si j ai quelque chose dans la static remaining provenant d un ancien appel de gnl.
 * Si il y a joindre line avec remaining j uste qu au premier \n puis faire egaler le restant a la static remaining.
 * 1. Copier la doite du \n le restant du buffer dans une static remaining et ce sans malloc.
 * 2. copier la gauche du \n la ligne vers la variable line incluant le \n.
 */

void	crop_line(char **line)
{
	static char	*remaining;

	if(remaining)
	{

	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_lenght;
	size_t	s2_lenght;

	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	if (s1 || s2)
	{
		s1_lenght = ft_strlen(s1);
		s2_lenght = ft_strlen(s2);
		s3 = malloc((s1_lenght + s2_lenght) + 1);
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, (s1_lenght + 1));
		ft_strlcat(s3, s2, ((s1_lenght + s2_lenght) + 1));
		return (s3);
		free((void *)s1);
		free((void *)s2);
	}
	return (NULL);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i != 3)
	{
		printf("Final returned value = %s\n", get_next_line(fd));
		i++;
	}
	return (0);
}
