	// Une fonction pour cree la nouvelle string

	// une fonction pour determiner le nombre de cut (si deux ou plus char ce suivent ex mettre un t de plus doit etre skip)

	// une fonction qui cut la string en d<autre strings

#include <stdio.h>
#include "libft.h"

// PREVIOUS VERSION OF FT_SPLIT // 

/*

// THE count_words FUNCTION //

static size_t	count_words(const char *s, const char c, size_t s_lenght, size_t word_count)
{
	while (s[s_lenght] != '\0')
	{
		if ((char)s[s_lenght] != c)
		{
			word_count++;
			while ((char)s[s_lenght] != c && s[s_lenght] != '\0')
				s_lenght++;
			count_words(s, c, s_lenght, word_count);
		}
		else
			s_lenght++;
	}
	return (word_count);
}


// THE word_lenght FUNCTION //

static size_t	word_lenght(const char *s, const char c, size_t s_lenght)
{
	size_t	count_char;

	count_char = 0;
	while (s[s_lenght] != '\0')
	{
		if ((char)s[s_lenght] == c)
			return (count_char);
		while ((char)s[s_lenght] == c)
				s_lenght++;
		count_char++;
		s_lenght++;
	}
	return (count_char); // grandeur du mot, pour malloc la substring
}

static char 	**make_master_str(size_t count)
{
	char	**new_empty_str;

	new_empty_str = malloc(sizeof(char*) * count);
	return (new_empty_str);
}

static char	*secondairy_str(const char *s, const char delemiter)
{
	char 	*new_str;
	size_t	i_s;
	size_t	i_new_str;
	size_t	lenght_of_word;

	i_s = 0;
	lenght_of_word = 0;
	i_new_str = 0;
	lenght_of_word = word_lenght(s, delemiter, i_s);
	new_str = malloc(sizeof(char *) * lenght_of_word)
	while (i_s != (i_s + lenght_of_word))
	{
		new_str[i_new_str] = s[i_s];
		i_s ++;
		i_new_str++;
	}
	new_str[i_new_str] = '\0';
	return (new_str);
}

// GENERAL TEST FUNCTION//


int	main(void)
{
	char	*s = "...1..12...123....1234.....12345......6....";
	size_t	s_lenght = 0;
	char	delemiter = '.';
	size_t	num_of_words;
	size_t	lenght_of_word;
	char	**str_of_str;
	size_t	i_str_of_str;
	num_of_words = 0;
	lenght_of_word = 0;
	i_str_of_str = 0;
	// COUNTING WORDS INTO STRING //
	num_of_words = count_words(s, delemiter, s_lenght, num_of_words);
	printf("Le nombre de mots est %zu\n", num_of_words);
	str_of_str = malloc(sizeof(char *) num_of_words)
	str_of_str = make_master_str(num_of_words);
	// COUNTING LENGHT OF EACH WORDS INTO STRING //
	printf("s_lenght after count words%zu\n", s_lenght);
	while (s[s_lenght] != '\0')
	{
		while (s[s_lenght] == delemiter)
			s_lenght++;
		if (lenght_of_word != 0)
		{
			str_of_str[i_str_of_str] = secondairy_str(&s[s_lenght], delemiter);
			s_lenght = s_lenght + lenght_of_word;
		}
	}
	printf("s_lenght after word lenght%zu\n", s_lenght);
	return (0);
}

*/




// NEW VERSION OF FT_SPLIT //

// THE ft_substr FUNCTION FOR COPYING EACH WORDS //
/*
static char	*ft_substr(char const *s, unsigned int start, size_t len) // len = word_size
{
	char	*dst;
	size_t	i_src;

	dst = malloc(sizeof((char)len + 1));
	if (!dst)
		return (0);
	if (start > len)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i_src = 0;
	while (s[i_src] != '\0')
	{
		if (i_src == start)
		{
			ft_strlcpy(dst, &s[i_src], (len + 1));
			return (dst);
		}
		i_src++;
	}
	free(dst);
	return ((char *)s);
}
*/

// THE FUNCTION FOR COUNTING EACH WORD //

static size_t	wordlenght(const char *s, const char c, size_t s_lenght)
{
	size_t	count_char;

	count_char = 0;
	while (s[s_lenght] != '\0')
	{
		if ((char)s[s_lenght] == c)
			return (count_char);
		//printf("WORDLENGHT FUNCTION TEST, la position dans la string est %zu \n\n", s_lenght);
		while ((char)s[s_lenght] != c && s[s_lenght] != '\0')
		{
			count_char++;
			s_lenght++;
		}
	}
	return (count_char); // grandeur du mot, pour malloc la substring
}

// THE FUNCTION FOR COUNTING THE NUMBER OF WORDS INTO THE STRING //

static size_t	count_words(const char *s, const char c, size_t s_lenght, size_t word_count)
{
	while (s[s_lenght] != '\0')
	{
		if ((char)s[s_lenght] != c)
		{
			word_count++;
			while ((char)s[s_lenght] != c && s[s_lenght] != '\0')
				s_lenght++;
			count_words(s, c, s_lenght, word_count);
		}
		else
			s_lenght++;
	}
	return (word_count);
}

// THE MASTER FUNCTION ORCHESTRING THE SPLIT //
char	**ft_split(char const *s, char c)
{
	size_t	s_lenght;
	size_t	num_of_words;
	size_t	lenght_of_word;
	char	**master_str;
	size_t	i_master_str;
	
	s_lenght = 0;
	num_of_words = 0;
	lenght_of_word = 0;
	i_master_str = 0;
	// COUNTING WORDS INTO STRING //
	num_of_words = count_words(s, c, s_lenght, num_of_words);
	//printf("FT_SPLIT FUNCTION TEST, le nombre total de mots dans la string est de %zu mots \n\n", num_of_words);
	// MALLOC THE MASTER_STR //
	master_str = malloc((sizeof(char *) * num_of_words) + 1);
	if (!master_str)
		return (0);
	// COUNTING LENGHT AND COPYING OF EACH WORDS INTO STRINGS //
	while (s[s_lenght] != '\0')
	{
		while (s[s_lenght] == c)
			s_lenght++;
		//printf("FT_SPLIT FUNCTION TEST, la position dans la string apres avoir passe les delemiter est %zu \n\n", s_lenght);
		lenght_of_word = wordlenght(s, c, s_lenght);
		//printf("FT_SPLIT FUNCTION TEST, la position dans la master string est a la case %zu du tableau \n\n", i_master_str);
		if (lenght_of_word != 0)
		{
			//printf("FT_SPLIT FUNCTION TEST, le nombre de charactere dans le mot est de %zu chars \n\n", lenght_of_word);
			master_str[i_master_str] = ft_substr(s, (unsigned int) s_lenght, lenght_of_word);
			s_lenght = s_lenght + lenght_of_word;
			//printf("FT_SPLIT FUNCTION TEST, le mot dans la string est: %s \n\n", master_str[i_master_str]);
			i_master_str++;
		}
	}
	//printf("FT_SPLIT FUNCTION TEST, la position dans la master string est a la case %zu du tableau \n\n", i_master_str);
	master_str[i_master_str] = NULL;
	return (master_str);
}



// GENERAL TEST FUNCTION//


int	main(void)
{
	const char	*source_str = ".sse.ee.fw..ed.a.bb.ccc.1234.12345..6.."; //23 chars
	char	delemiter = '.';
	char	**str_of_str;
	size_t	i_str_of_str;

	printf("\nMAIN FUNCTION TEST, la string source est : %s\n\n", source_str);
	str_of_str = ft_split(source_str, delemiter);
	i_str_of_str = 0;
		
	while (i_str_of_str < 11)
	{
		printf("Les adresses alloue sont : %p\n", &str_of_str[i_str_of_str]);
		printf("Les mots sont : %s\n", str_of_str[i_str_of_str]);
		i_str_of_str++;
	}
	return (0);
}


// OLD FUNCTION//

/*
static char 	*make_str(size_t count)
{
	char	*new_empty_str;

	new_empty_str = malloc(sizeof(char*) * count);
	return (new_empty_str);
}
*/


// GENERAL TEST FUNCTION//
/*
int	main(void)
{
	char	*s = "...1..12...123....1234.....12345......6....";
	size_t	s_lenght = 0;
	char	delemiter = '.';
	size_t	num_of_words = 0;
	size_t	lenght_of_word;
	char	str_of_str;

	lenght_of_word = 0;
	// COUNTING WORDS INTO STRING //
	num_of_words = count_words(s, delemiter, s_lenght, num_of_words);
	printf("Le nombre de mots est %zu\n", num_of_words);
	str_of_str = *make_str(num_of_words);
	// COUNTING LENGHT OF EACH WORDS INTO STRING //
	printf("s_lenght after count words%zu\n", s_lenght); //pas utiliser dans la fonction
	while (s[s_lenght] != '\0')
	{
		while (s[s_lenght] == delemiter)
			s_lenght++;
		lenght_of_word = word_lenght(s, delemiter, s_lenght);
		if (lenght_of_word != 0)
			printf("La langueur du mots est de %zu chars\n", lenght_of_word);
		s_lenght = s_lenght + lenght_of_word;
	}
	printf("s_lenght after word lenght%zu\n", s_lenght); //utiliser dans la fonction
	return (0);
}
*/

/*
// THE ft_split FUNCTION (MASTER) //

char	**ft_split(const char *s, const char c)
{
	char	*str = "str..mdr.rdr.ptr";
	size_t	i;
	size_t	word_size;
	char 	*str_of_str;

	i = 0;
	word_size = 0;
	str_of_str = malloc(la_fonction_qui_check_le_nombre_de_mot)
	while (str[i])
	{
		i = word_size;
		word_size = word_lenght(str, c, i);
		while (s[i] != '\0')
		{
			s[i] = ft_substr(s, i, word_size) // len = word_size
			while ((char *)str[i] == c)
				i++;
		}
	}
	return (str_of_str);
}
*/
	// utiliser ft_substr (char const *s, unsigned int start, size_t len) pour les nouvelles chaines
	// char const *s, sera la string
	// unsigned int start, sera la position ou commence la coupure
	// size_t len, la longeur entre deux coupures



// ------SIMILAR FUNCTION------ //

/*
// FUNCTION count_words WITH WHILE LOOPS NO RECURSIVE //

static size_t	count_words(const char *s, const char c)
{
	size_t	i_s;
	size_t	count;

	i_s = 0;
	count = 0;
	while (s[i_s] != '\0')
	{
		if ((char)s[i_s] == c)
			i_s++;
		if ((char)s[i_s] != c)
		{
			if ((char)s[i_s - 1] == c)
				count++;
			i_s++;
		}
	}
	return (count);
}
*/


// ------FUNCTIONS TEST------ //
/*
// TEST count_words FUNCTION //

int	main(void)
{
	char	*s = ".str...mdr..rdr.ptr...";
	size_t	s_lenght = 0;
	size_t	word_count = 0;
	char 	delemiter = '.';
	// RECURSIVE FUNCTION //
	printf("Le nombre de mots est %zu\n", count_words(s, delemiter, s_lenght, word_count));
	// WHILE LOOP FUNCTION //
	//printf("Le nombre de mots est %zu\n", count_words(s, delemiter));

	
	return (0);
}
*/
//##-----###------####------#####------####------###-----##//
/*
// TEST word_lenght FUNCTION //

int	main(void)
{
	char	*s = "...1..12...123....1234.....12345......6....";
	size_t	s_lenght = 0;
	char 	delemiter = '.';
	size_t	lenght_of_word;

	lenght_of_word = 0;
	// RECURSIVE FUNCTION //
	// WHILE LOOP FUNCTION //
	while (s[s_lenght] != '\0')
	{
		while (s[s_lenght] == delemiter)
			s_lenght++;
		lenght_of_word = word_lenght(s, delemiter, s_lenght);
		if (lenght_of_word != 0)
			printf("La langueur du mots est de %zu chars\n", lenght_of_word);
		s_lenght = s_lenght + lenght_of_word;
	}
	
	return (0);
}
*/

