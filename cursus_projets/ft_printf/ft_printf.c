/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:11:28 by tchalifo          #+#    #+#             */
/*   Updated: 2021/12/08 17:49:40 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_selector(const char *str, t_print *p_data)
{
	//ft_putnbr(p_data->i);
	//write(1, "b", 1);
	if (str[p_data->i] == 'd' || str[p_data->i] == 'i')
	{
		p_data->count = p_data->count + ft_putstr(ft_itoa(va_arg(p_data->valist, int))); // je doit compter tout les chiffres utiliser numlen !!
		p_data->i++;
	}
	//ft_putnbr(p_data->i);
	if (str[p_data->i] == 'c')
	{
		p_data->count = p_data->count + write(1, va_arg(p_data->valist, char *), 1);
		p_data->i++;
	}
	if (str[p_data->i] == 's')
	{
		ft_putnbr(p_data->count);
		p_data->count = p_data->count + ft_putstr(va_arg(p_data->valist, char *));
		ft_putnbr(p_data->count);
		p_data->i++;
	}
	if(str[p_data->i] == 'u')
	{
		p_data->count = p_data->count + ft_putstr(ft_itoa(va_arg(p_data->valist)))
	}

}


int	ft_printf(const char *str, ...)
{
	t_print	*data;

	data = (t_print *) malloc(sizeof(t_print));
	if (!data)
		return (-1);
	va_start(data->valist, str);
	data->i = 0;
	data->count = 0;
	while (str[data->i] != '\0')
	{
		ft_putchar(str[data->i]);
		data->i++;
		data->count++;
		if (str[data->i] == '%')
		{
			//ft_putnbr(data->i);
			//write(1, "a", 1);
			data->i++;
			//ft_putnbr(data->i);
			type_selector(str, data);
		}
		//ft_putnbr(data->count);

	}

	return (data->count);
}

int	main(void)
{
	//int	count_num;

	//count_num = 0;
	ft_printf("Bonjour %s123%d\n", "zero", 5);
	//ft_printf("nombre de chars = %d", count_num);
	return (0);
}
