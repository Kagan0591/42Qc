/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:56:42 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/14 10:56:52 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(numlen(n) + 1);
	if (!str)
		return (0);
	i = (numlen(n));
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[i--] = '\0';
	while (n > 9)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	str[i] = n + 48;
	return (str);
}
