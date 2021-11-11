/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:55:14 by tchalifo          #+#    #+#             */
/*   Updated: 2021/11/11 18:38:22 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*result;

	fd = open("file.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("Final returned value = '%s'\n", result);
	return (0);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*remaining;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (get_line(fd, &remaining) == 0)
		return (NULL);
	printf("GNL: remaining = %s\n", remaining); // ------> A partir de cette ligne, apres avoir passer dans get_line une erreur de free un non malloc ce produit
	line = crop_front(remaining);
	remaining = crop_end(remaining);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	get_line(int fd, char **remaining_ptr)
{
	char		*buffer;
	int			read_output;

	read_output = 1;
	buffer = malloc(sizeof(char*) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		return (0);
	}
	while (!ft_strchr(*remaining_ptr, '\n') && read_output != 0)
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		buffer[read_output] = '\0';
		if (read_output == -1)
		{
			free(buffer);
			return (0);
		}
		printf("GET_LINE: buffer before memjoin = '%s'\n", buffer);
		printf("GET_LINE: remaining before memjoin = '%s'\n", *remaining_ptr);
		printf("GET_LINE: read_output = %d\n", read_output);
		printf("GET_LINE: ADD DE remaining_ptr == %p\n", remaining_ptr);
		printf("GET_LINE: ADD DE buffer == %p\n", buffer);
		*remaining_ptr = ft_memjoin(*remaining_ptr, buffer);
		printf("GET_LINE: remaining after memjoin = '%s'\n", *remaining_ptr);
		printf("GET_LINE: buffer after memjoin = '%s'\n", buffer);
	}
	//free(buffer);
	printf("GET_LINE: test\n");
	//buffer = NULL;
	return (1);
}

char	*ft_memjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_length;
	size_t	s2_length;
	printf("MEMJOIN: Start s1 = %s\n", s1);
	printf("MEMJOIN: start s2 = %s\n", s2);
	printf("MEMJOIN: ADD DE s1 == %p\n", s1);
	printf("MEMJOIN: ADD DE s2 == %p\n", s2);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	if (!s1 && s2)
	{
		printf("test\n");
		return (ft_strdup(s2));
	}
	else if (!s2 && s1)
	{
		printf("test\n");
		return (ft_strdup(s1));
	}
	else if (s1 && s2)
	{
		s3 = malloc(sizeof(char) * (s1_length + s2_length) + 1);
		if (!s3)
			return (NULL);
		printf("MEMJOIN: TEST sur s2 == %s\n", s2);
		printf("MEMJOIN: ADD DE s1 == %p\n", s1);
		printf("MEMJOIN: ADD DE s2 == %p\n", s2);
		printf("MEMJOIN: ADD DE s3 after malloc == %p\n", s3);
		ft_strlcpy(s3, s1, (s1_length + 1));
		printf("MEMJOIN: end s3 = %s\n", s3);
		printf("MEMJOIN: end s2 = %s\n", s2);
		ft_strlcat(s3, s2, ((s1_length + s2_length) + 1));
		free((void*)s1);
		printf("MEMJOIN: s3 after cat = '%s'\n", s3);
		return (s3);
	}
	return (NULL);
}

char	*crop_front(char *src)
{
	int		lenght;
	int		i;
	char	*dst;
	printf("CROP_FRONT: test");

	lenght = 0;
	i = 0;
	while (src[lenght] && src[lenght] != '\n')
		lenght++;
	dst = malloc(sizeof(char) * (lenght + 1));
	while (i <= lenght)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*crop_end(char *src)
{
	size_t	i;

	i = 0;
	if (*src != '\0')
	{
		while (src[i] && src[i] != '\n')
			i++;
		if (src[i] == '\n')
			return (ft_strdup(&src[i] + 1));
		else
			return (ft_strdup(src));
	}
	free((void*)src);
	return (NULL);
}
