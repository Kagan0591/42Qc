/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:37:48 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/01 16:38:04 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// THE FUNCTION FOR COUNTING THE NUMBERS OF CHARACTERE INTO WORDS //
static size_t	wordlenght(const char *s, const char delemiter, size_t s_lenght)
{
	size_t	count_char;

	count_char = 0;
	while (s[s_lenght] != '\0')
	{
		if ((char)s[s_lenght] == delemiter)
			return (count_char);
		while ((char)s[s_lenght] != delemiter && s[s_lenght] != '\0')
		{
			count_char++;
			s_lenght++;
		}
	}
	return (count_char);
}

// THE FUNCTION FOR COUNTING THE NUMBER OF WORDS INTO THE STRING //
static size_t	count_words(char *s, char delemiter, size_t s_lenght, size_t word_count)
{
	while (s[s_lenght] != '\0')
	{
		if (s[s_lenght] != delemiter)
		{
			word_count++;
			while (s[s_lenght] != delemiter && s[s_lenght] != '\0')
				s_lenght++;
			count_words(s, delemiter, s_lenght, word_count);
		}
		else
			s_lenght++;
	}
	return (word_count);
}

// THE FUNCTION TO MAKE THE MASTER STRING //
static char	**make_master_str(size_t count, size_t size)
{
	char	**new_empty_str;

	new_empty_str = malloc(count * size);
	if (!new_empty_str)
		return (0);
	return (new_empty_str);
}

// THE MASTER FUNCTION ORCHESTRING THE SPLIT //
char	**ft_split(char const *s, char c)
{
	size_t	s_lenght;
	size_t	lenght_of_word;
	char	**master_str;
	size_t	i_master_str;

	s_lenght = 0;
	lenght_of_word = 0;
	i_master_str = 0;
	master_str = make_master_str(\
		(count_words((char *)s, c, s_lenght, 0) + 1), sizeof(char *));
	while (s[s_lenght] != '\0')
	{
		while (s[s_lenght] == c)
			s_lenght++;
		lenght_of_word = wordlenght(s, c, s_lenght);
		if (lenght_of_word != 0)
		{
			master_str[i_master_str] = ft_substr(\
				s, (unsigned int) s_lenght, lenght_of_word);
			s_lenght = s_lenght + lenght_of_word;
			i_master_str++;
		}
	}
	master_str[i_master_str] = NULL;
	return (master_str);
}
