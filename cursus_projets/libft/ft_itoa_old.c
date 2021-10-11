#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <string.h>

int	ft_numlen(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	printf("FT_NUMLEN %d charactere(s)\n", i);
	return (i);
}

char	*make_array(size_t count)
{
	char	*array;

	printf("MAKE_ARRAY %zu charactere(s)\n", count);
	array = malloc(sizeof(char *) * count);
	return (array);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i_str;

	i_str = 0;
	str = make_array(ft_numlen(n) + 1);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i_str = ft_numlen(n) + 1;
	}
	if (n == 0)
	{
		str[i_str] = '0';
		i_str++;
	}
	while (n >= 10)
	{
		str[i_str] = (n % 10) + 48;
		n = n / 10;
		i_str--;
		printf("%c\n", str[i_str]);
		printf("BOUCLE WHILE %d\n", n);
	}
	str[i_str--] = (n % 10) + 48;
	str[i_str] = '\0';
	printf("FT_ITOA %s\n", str);
	return (str);
}

int	main(void)
{
	int	number;

	number = -333334;
	printf("MAIN %s\n", ft_itoa(number));
	return (0);
}

