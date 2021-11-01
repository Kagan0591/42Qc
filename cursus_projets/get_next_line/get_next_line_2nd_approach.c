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
/* get_line est utilise pour retrouver BUFFER_SIZE nombres de charactere
 * dans un fichier puis les ecrires dans la variable char *buffer.
 * Ensuite, il joint le buffer a la chaine line. Puis, il s assurera de copier
 * dans la chaine remaining le reste du buffer */
char	*get_line(int fd, line)
{
	static char	*remaining;		// Ce qui restera du buffer apres le retour de ligne
	char		*buffer;		// Le tempon ou est stocke les characteres provenant du fichier
	char		*line;			// La chaine de charactere destine a contenire toute la ligne
	int			read_output;	// Le nombre de characteres ecrit dans le buffer, retourne par la fonction read

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE));	// Alloue l espace au buffer selon le BUFFER_SIZE
	if (remaining != '\0')								// Verifie si il y a un reste de l ancient buffer
		line = ft_strjoin(line, remaining);				// Si il y a, il joindra la chaine remaining a la chaine line
	read_output = 1;									// Initialise la variable read_output a 1, pusique 0 egale
	while (read_output != 0)							// Tant que la variable read-output n egale pas 0 (read retourne 0 quand il atteint END_OF_FILE)
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		if (read_output == -1)							// Verifie si la varable read-output est egale a -1 (read retourne -1 quand il ya a erreur)
			return (0);									// Si vrai, la fonction retourne 0
		buffer =
		if (!line)										// Verifie si la chaine line existe (Elle ne devrait pas si il sagit de la premiere iteration et/ou si remaining ne contenais rien)
			line = malloc(1);							// si vrai, la chaine line ce voit allouer dynamiquement un espace en memoire de un octet
		line = ft_strjoin(line, buffer);				// La chaine buffer est jointe a la chaine line pour y ajouter sont contenue a la suite de cette derniere
		free(buffer);									// N ayant plus besoin du contenue de la chaine buffer, l espace memoire qui lui etait allouee est liberee
	}

}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}


/* get_next_line est utilise pour retrouver BUFFER_SIZE nombres de charactere
 * dans un fichier puis les ecrires dans la variable char *buffer. */
char	*get_next_line(int fd)
{
	char	*line;

	line = get_line(fd);

}
