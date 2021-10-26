/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_1st_approach.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:05:22 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/26 16:53:28 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Calling your function get_next_line in a loop will then allow you to read the text
 * available on the file descriptor one line at a time until the end of it.
 * Appeler la fonction get_next_line dans un loop, ce qui me permettra
 * de lire le fichier texte depuis le file descriptor une ligne a la fois jusqu'a la fin
 *
 * Fonction read tentera de lire count nombre d octet depuis le fd dans un buffer commencant a *buf */

#include "get_next_line.h"
#include <stdio.h>

/* get_line prend la string temp et cree une string en joint les differents buffer
 *
 * READ
 * A chaque fois que read est utilie , il garde sa position en lecture, donc si je lis 10 chars une premiere fois,
 * a la seconde fois il continura de lire depuis la 10 ieme position */
// char	*get_line(char * read_out)
// {

// }
static int test;
char	*get_next_line(int fd)
{
	char	*buffer;
	char	*buffer2;
	size_t	count_chars;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	buffer2 = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	count_chars = 0;
	count_chars = read(fd, buffer, BUFFER_SIZE);
	printf("1 st read call %zu\n", count_chars);
	printf("1 st read call %s\n", buffer);
	count_chars = read(fd, buffer, BUFFER_SIZE);
	printf("2nd read call %zu\n", count_chars);
	printf("2nd read call %s\n", buffer);
	buffer[BUFFER_SIZE + 1] = '\0';
	test = 29;
	printf("\n%d\n", test);

	return (buffer);
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
