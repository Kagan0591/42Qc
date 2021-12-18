/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:11:28 by tchalifo          #+#    #+#             */
/*   Updated: 2021/12/17 15:04:26 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_selector(const char *str, t_print *p_data)
{
	if (str[p_data->i] == 'd' || str[p_data->i] == 'i')
		p_data->count = p_data->count + ft_putnbr(va_arg(p_data->valist, int));
		//ft_putstr(ft_itoa(va_arg(p_data->valist, int)));
	else if(str[p_data->i] == 'u')
		p_data->count = p_data->count + ft_putnbr_unsigned(va_arg(p_data->valist, int));
	else if (str[p_data->i] == 'X')
		p_data->count = p_data->count + ft_putnbr_Hexa(va_arg(p_data->valist, long));
	else if (str[p_data->i] == 'x')
		p_data->count = p_data->count + ft_putnbr_hexa(va_arg(p_data->valist, long));
	else if (str[p_data->i] == 'c')
		p_data->count = p_data->count + ft_putchar(va_arg(p_data->valist, int));
	else if (str[p_data->i] == 's')
		p_data->count = p_data->count + ft_putstr(va_arg(p_data->valist, char *));
	else if (str[p_data->i] == 'p')
		p_data->count = p_data->count + ft_putmem(va_arg(p_data->valist, char *));
	else
		return (0);
	p_data->i++;
	return (1);
}


int	ft_printf(const char *str, ...)
{
	t_print	data;

	// data = (t_print *) malloc(sizeof(t_print));
	// if (!data)
	// 	return (-1);
	va_start(data.valist, str);
	data.i = 0;
	data.count = 0;
	while (str[data.i] != '\0')
	{
		if (str[data.i] == '%')
		{
			data.i++;
			type_selector(str, &data);
		}
		else
		{
			ft_putchar(str[data.i]);
			data.i++;
			data.count++;
		}
	}

	return (data.count);
}
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	char *str;
	str = "Bonjour";

	ft_printf("\nPrint unsigned int with negative number: %u\n", -42);
	printf("Print unsigned int with negative number from original printf: %u\n\n", -42);

	ft_printf("Print unsigned int MAX_VALUE: %u\n", UINT_MAX);
	printf("Print unsigned int MAX_VALUE from original printf: %u\n\n", UINT_MAX);

	ft_printf("Print int INT_MIN number: %d\n", INT_MIN);
	printf("Print int INT_MIN number from original printf: %d\n\n", INT_MIN);

	ft_printf("Print int INT_MAX number: %u\n", INT_MAX);
	printf("Print int INT_MAX number from original printf: %u\n\n", INT_MAX);

	ft_printf("Print d'un caractere: %c\n", 'c');
	printf("Print d'un caractere: %c\n\n", 'c');

	ft_printf("Print d'une chaine de caractere: %s\n", "Test d'une chaine");
	printf("Print d'une chaine de caractere: %s\n\n", "Test d'une chaine");

	ft_printf("Print HEXA_number with negative number: %X\n", -42);
	printf("Print HEXA_number with negative number from original printf: %X\n\n", -42);

	ft_printf("Print HEXA_number INT_MAX number: %X\n", INT_MAX);
	printf("Print HEXA_number INT_MAX number from original printf: %X\n\n", INT_MAX);

	ft_printf("Print HEXA_number INT_MIN number: %X\n", INT_MIN);
	printf("Print HEXA_number INT_MAX number from original printf: %x\n\n", INT_MIN);

	ft_printf("Print hexa_number with negative number: %X\n", -42);
	printf("Print hexa_number with negative number from original printf: %X\n\n", -42);

	ft_printf("Print hexa_number INT_MAX number: %X\n", INT_MAX);
	printf("Print hexa_number INT_MAX number from original printf: %X\n\n", INT_MIN);

	ft_printf("Print hexa_number INT_MIN number: %X\n", INT_MIN);
	printf("Print HEXA_number INT_MIN number from original printf: %x\n\n", INT_MIN);

	ft_printf("Print pointeur address: %p\n", str);
	printf("Print pointeur address from original printf: %p\n\n", str);
}
