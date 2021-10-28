/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_1st_approach.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:05:22 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/28 12:29:28 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Calling your function get_next_line in a loop will then allow you to read the text
 * available on the file descriptor one line at a time until the end of it.
 * Appeler la fonction get_next_line dans un loop, ce qui me permettra
 * de lire le fichier texte depuis le file descriptor une ligne a la fois jusqu'a la fin
 *
 * READ
 * Fonction read tentera de lire count nombre d octet depuis le fd dans un buffer commencant a *buf
 *  A chaque fois que read est utilie , il garde sa position en lecture, donc si je lis 10 chars une premiere fois,
 * a la seconde fois il continura de lire depuis la 10 ieme position
 *
 * get_line read la ligne au complet et
 * */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(int fd)
{
	char		*buffer1;
	char		*buffer2;
	static char *keep_the_rest;
	size_t		buffer2_lenght;
	int			bytes_read;

	buffer1 = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer1)
		return (0);
	bytes_read = 1;
	buffer2_lenght = 0;
	printf("%zu\n", buffer2_lenght);
	buffer2 = keep_the_rest;
	while (bytes_read != 0 && bytes_read != -1 && buffer2[buffer2_lenght] != '\n')
	{
		bytes_read = read(fd, buffer1, BUFFER_SIZE);
		buffer1 = ft_strchr_and_destroy(buffer1, keep_the_rest, '/n');
		buffer2 = ft_strjoin(buffer2, buffer1);
		buffer2_lenght = ft_strlen(buffer2);
	}
	free(buffer1);
	printf("%s\n", buffer2);
	return (buffer2);
}

char	*ft_strchr_and_destroy(const char *s, char *keep, int c)
{
	size_t	i_s;

	i_s = 0;
	while (s[i_s])
	{
		if (s[i_s] == (char)c)
		{
			strlcpy(keep, s[i_s + 1], ft_strlen(s[i_s])); // Copie les elements de la chaine apres le /n dans une chaine tmp
			ft_memset(s[i_s + 1], '/0', ft_strlen(s[i_s + 1])); // met a zero les elements de la chaine apres le /n
			return ((char *)s); // retourne la chaine tronquer
		}
		i_s++;
	}
	return ((char) *s);
}

char	*get_next_line(int fd)
{
	char	*tmp_buf;

	tmp_buf = get_line(fd);
	return (tmp_buf);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*buffer;

	test = 20;
	fd = open("test.txt", O_RDONLY);
	buffer = get_next_line(fd);
	return (0);
}
