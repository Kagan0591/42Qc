/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:09:58 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/29 17:51:03 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	printf("%s\n", s);
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = (ft_strlen(s) - start);
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, ((char *)s + start), (len + 1));
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i_s1;

	i_s1 = ft_strlen(s1) + 1;
	s2 = malloc(sizeof(*s2) * i_s1);
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, i_s1);
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i_s;

	i_s = 0;
	while (s[i_s] != '\0')
		i_s++;
	return (i_s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclenght;
	srclenght = ft_strlen(src);
	if (dstsize == 0)
		return (srclenght);
	while (*src && dstsize-- > 1)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (srclenght);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	destlenght;
	size_t	srclenght;

	i_dest = 0;
	i_src = 0;
	destlenght = ft_strlen(dst);
	srclenght = ft_strlen((char *)src);
	if (dstsize < destlenght)
		return (dstsize + srclenght);
	while (dst[i_dest])
		i_dest++;
	while (src[i_src] && (i_dest + 1) < dstsize)
	{
		dst[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dst[i_dest] = '\0';
	return (destlenght + srclenght);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len--)
		*str++ = (unsigned char)c;
	return (b);
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

static size_t	wordlenght(const char *s, const char delemiter, size_t i_s)
{
	size_t	count_char;

	count_char = 0;
	while (s[i_s] != '\0')
	{
		if ((char)s[i_s] == delemiter)
			return (count_char);
		while ((char)s[i_s] != delemiter && s[i_s] != '\0')
		{
			count_char++;
			i_s++;
		}
	}
	return (count_char);
}

static size_t	count_words(char *s, char delemiter, size_t i_s, size_t count)
{
	while (s[i_s] != '\0')
	{
		if (s[i_s] != delemiter)
		{
			count++;
			while (s[i_s] != delemiter && s[i_s] != '\0')
				i_s++;
			count_words(s, delemiter, i_s, count);
		}
		else
			i_s++;
	}
	return (count);
}

static void	makestr(char *string_source, char **string_master, char c)
{
	size_t	string_source_lenght;
	size_t	i_string_master;
	size_t	lenght_of_word;

	string_source_lenght = 0;
	i_string_master = 0;
	lenght_of_word = 0;
	while (string_source[string_source_lenght] != '\0')
	{
		while (string_source[string_source_lenght] == c)
			string_source_lenght++;
		lenght_of_word = wordlenght(string_source, c, string_source_lenght);
		if (lenght_of_word != 0)
		{
			string_master[i_string_master] = ft_substr(\
				string_source, (unsigned int) string_source_lenght, \
					lenght_of_word);
			string_source_lenght = string_source_lenght + lenght_of_word;
			i_string_master++;
		}
	}
	string_master[i_string_master] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	lenght_of_word;
	char	**master_str;

	lenght_of_word = 0;
	if (!s)
		return (0);
	master_str = malloc((count_words((char *)s, c, 0, 0) + 1) * sizeof(char *));
	if (!master_str)
		return (0);
	makestr((char *)s, master_str, c);
	return (master_str);
}
