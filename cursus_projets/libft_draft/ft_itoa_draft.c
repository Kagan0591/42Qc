#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <string.h>

int	ft_numlen(int n)
{
	char	*str;
	int	i;

	i = 1;
	if (n < 0)
	{
		n * - 1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	printf("Le nombre est de %d charactere(s)\n", i);
	return (i);
}

char 	*make_array(size_t count)
{
	void	array;
	printf("Le nombre est de %d charactere(s)\n", array_lenght);
	array = malloc(sizeof(char *) * array_lenght);
	return (array);
}

char *ft_itoa(int n)
{
	char	*str;
	int	n_lenght
	int	n_temp;
	int	i_str;

	i_str = 0;
	str_lenght = ft_numlen(n);
	str = make_array(str_lenght + 1);
	if (n < 0)
	{
		str[i_str] = '-';
		n = n * -1; // Remettre le nombre n positif pour la suite
		i_str++;
	}
	if (n == 0)
	{
		str[i_str] = '0';
		i_str++;
	}
	i_str = i_str + n_lenght;
	while (n > 10)
	{
		str[i_str] = (n % 10) + 48;
		n = n / 10;
		i_str--;
	}
	return (str);
}



// recursive

char *ft_itoa(int n)
{
	char *str;

	//if(!(str = (char *)malloc(sizeof(char) * 2)));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	(str = (char *)malloc(sizeof(char) * 2));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
		//printf("%s\n", str);
	else if (n < 10 && n >= 0)
	{
		str[0] = n + 48;
		str[1] = '\0';
	}
	return (str);
}


int	main(void)
{
	int	number;

	number = -214648;
	printf("%s\n", ft_itoa(number));
	return (0);
}