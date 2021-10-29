/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2nd_approach.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:30:53 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/29 17:56:57 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;

	get_line(fd, line);
}

char	*get_line(int fd)
{
	static char	*remaining;
	char	buffer;
	int	read_output;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	while (read_output != 0)
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		if (read_output == -1)
			return (0);
		ft_strjoin()
	}

}
