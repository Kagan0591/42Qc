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
	else if(str[p_data->i] == 'u')
		p_data->count = p_data->count + ft_putnbr_unsigned(va_arg(p_data->valist, unsigned int));
	else if (str[p_data->i] == 'X')
		p_data->count = p_data->count + ft_putnbr_Hexa(va_arg(p_data->valist, unsigned long));
	else if (str[p_data->i] == 'x')
		p_data->count = p_data->count + ft_putnbr_hexa(va_arg(p_data->valist, unsigned long));
	else if (str[p_data->i] == 'c')
		p_data->count = p_data->count + ft_putchar(va_arg(p_data->valist, int));
	else if (str[p_data->i] == 's')
		p_data->count = p_data->count + ft_putstr(va_arg(p_data->valist, char *));
	else if (str[p_data->i] == 'p')
		p_data->count = p_data->count + ft_putmem(va_arg(p_data->valist, char *));
	else if (str[p_data->i] == '%')
		p_data->count = p_data->count + ft_putchar('%');
	else
		return (0);
	p_data->i++;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	t_print	data;

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
	char	*addtest;
	long	count;

	ft_printf("Print a string: %s\n", "Test d'une chaine");
	printf("Print a string from original printf: %s\n\n", "Test d'une chaine");
//--TEST char "%c"
	ft_putstr("TEST %c\n");
	ft_putstr("Print a single charactere 't' %c: ");
	count = ft_printf("%c", 't');
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a single charactere 't' from original printf %c: ");
	count = printf("%c", 't');
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("TEST %c\n");
	ft_putstr("Print a single charactere 't' multiple time %c: ");
	count = ft_printf("%c%c%c", 't', 't', 't');
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a single charactere 't' multiple time from original printf %c: ");
	count = printf("%c", 't');
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
//--TEST unsigned int "%u"
	ft_putstr("TEST %u\n");
	ft_putstr("Print a negative number with an unsigned int %u: ");
	count = ft_printf("%u", -42);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a negative number with an unsigned int from original printf %u: ");
	count = printf("%u", -42);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MAX_VALUE of an unsigned int %u: ");
	count = ft_printf("%u", UINT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MAX_VALUE of an unsigned int from original printf %u: ");
	count = printf("%u", UINT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print a zero with an unsigned int %u: ");
	count =ft_printf("%u", 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a zero with an unsigned int from original printf %u: ");
	count = printf("%u", 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the INT_MIN_VALUE with an unsigned int %u: ");
	count =ft_printf("%u", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the INT_MIN_VALUE with an unsigned int from original printf %u: ");
	count = printf("%u", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the INT_MAX_VALUE with an unsigned int %u: ");
	count =ft_printf("%u", INT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the INT_MAX_VALUE with an unsigned int from original printf %u: ");
	count = printf("%u", INT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the LONG_MIN_VALUE with an unsigned int %u: ");
	count =ft_printf("%u", LONG_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the LONG_MAX_VALUE with an unsigned int %u: ");
	count =ft_printf("%u", LONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the ULONG_MAX_VALUE with an unsigned int %u: ");
	count =ft_printf("%u", ULONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

//--TEST multiple variables unsigned int "%u"
	ft_putstr("Print multiple %u");
	count = ft_printf("%u %u %u %u %u %u %u %u", UINT_MAX, 0, INT_MIN, INT_MAX, LONG_MAX, LONG_MIN, ULONG_MAX, -42);
	ft_putstr("\nTested: UINT_MAX, 0, INT_MIN, INT_MAX, LONG_MAX, LONG_MIN, ULONG_MAX, -42)");
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

//--TEST int "%d et %i"
	ft_putstr("TEST %d\n");
	ft_putstr("Print a negative number with int %d: ");
	count = ft_printf("%d", -1);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a negative number with int %d from original printf: ");
	count = printf("%d", -1);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MAX_VALUE of an int %d: ");
	count = ft_printf("%d", UINT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MAX_VALUE of an int %d from original printf: ");
	count = printf("%d", UINT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MIN_VALUE of an int %d: ");
	count = ft_printf("%d", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MIN_VALUE of an int %d from original printf: ");
	count = printf("%d", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print a 0 with an int %d: ");
	count = ft_printf("%d", 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a 0 with an int %d from original printf: ");
	count = printf("%d", 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the LONG_MAX_VALUE of an int %d: ");
	count = ft_printf("%d", LONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;


	ft_putstr("Print the LONG_MIN_VALUE of an int %d: ");
	count = ft_printf("%d", LONG_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the ULONG_MAX_VALUE of an int %d: ");
	count = ft_printf("%d", ULONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

//--TEST multiple variables int "%d"
	ft_putstr("Print multiple %d");
	count = ft_printf("%d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_putstr("Tested: INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)");
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

//--TEST hexa %x
	ft_putstr("TEST %x\n");
	ft_putstr("Print the number 42 with int in hexa %x: ");
	count = ft_printf("%x", 42);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the number 42 with int in hexa %x from original printf: ");
	count = printf("%x", 42);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the number 16 with int in hexa %x: ");
	count = ft_printf("%x", 16);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the number 16 with int in hexa %x from original printf: ");
	count = printf("%x", 16);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print a negative number with int in hexa %x: ");
	count = ft_printf("%x", -1);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a negative number with int in hexa %x from original printf: ");
	count = printf("%x", -1);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MIN_VALUE of an int in hexa %x: ");
	count = ft_printf("%x", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MIN_VALUE of an int in hexa %x from original printf: ");
	count = printf("%x", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MAX_VALUE of an int in hexa %x: ");
	count = ft_printf("%x", INT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MAX_VALUE of an int in hexa %x from original printf: ");
	count = printf("%x", INT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MAX_VALUE of an unsigned int in hexa %x: ");
	count = ft_printf("%x", UINT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MAX_VALUE of an int in hexa %x from original printf: ");
	count = printf("%x", UINT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print a 0 with an int in hexa %x: ");
	count = ft_printf("%x", 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a 0 with an int in hexa %x from original printf: ");
	count = printf("%x", 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the LONG_MAX_VALUE of an int in hexa %x: ");
	count = ft_printf("%x", LONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the LONG_MIN_VALUE of an int in hexa %x: ");
	count = ft_printf("%x", LONG_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the ULONG_MAX_VALUE of an int in hexa %x: ");
	count = ft_printf("%x", ULONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the aphanumeric number 9223372036854775807LL with an int in hexa %x: ");
	count = ft_printf("%x", 9223372036854775807LL);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

//--TEST HEXA %X
	ft_putstr("TEST %X\n");
	ft_putstr("Print the number 42 with int in hexa %X: ");
	count = ft_printf("%X", 42);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the number 42 with int in hexa %X from original printf: ");
	count = printf("%X", 42);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the number 16 with int in hexa %X: ");
	count = ft_printf("%X", 16);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the number 16 with int in hexa %X from original printf: ");
	count = printf("%X", 16);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print a negative number with int in hexa %X: ");
	count = ft_printf("%X", -1);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a negative number with int in hexa %X from original printf: ");
	count = printf("%X", -1);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MIN_VALUE of an int in hexa %X: ");
	count = ft_printf("%X", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MIN_VALUE of an int in hexa %X from original printf: ");
	count = printf("%X", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MAX_VALUE of an int in hexa %X: ");
	count = ft_printf("%X", INT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MAX_VALUE of an int in hexa %X from original printf: ");
	count = printf("%X", INT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the MAX_VALUE of an unsigned int in hexa %X: ");
	count = ft_printf("%X", UINT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the MAX_VALUE of an int in hexa %X from original printf: ");
	count = printf("%X", UINT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print a 0 with an int in hexa %X: ");
	count = ft_printf("%X", 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print a 0 with an int in hexa %X from original printf: ");
	count = printf("%X", 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the LONG_MAX_VALUE of an int in hexa %X: ");
	count = ft_printf("%X", LONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the LONG_MIN_VALUE of an int in hexa %X: ");
	count = ft_printf("%X", LONG_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the ULONG_MAX_VALUE of an int in hexa %X: ");
	count = ft_printf("%X", ULONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the aphanumeric number 9223372036854775807LL with an int in hexa %X: ");
	count = ft_printf("%X", 9223372036854775807LL);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

//--TEST addresse memoire %p
	addtest = "Bonjour";

	ft_putstr("TEST %p\n");
	ft_putstr("Print the pointeur address: %p: ");
	count = ft_printf("%p", addtest);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
	ft_putstr("Print the pointeur address from original printf: %p: ");
	count = printf("%p", addtest);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the address from a LONG_MIN_VALUE %p: ");
	count = ft_printf("%p", LONG_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the address from a INT_MIN_VALUE %p: ");
	count = ft_printf("%p", INT_MIN);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the address from a ULONG_MIN_VALUE %p: ");
	count = ft_printf("%p", -ULONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");

	ft_putstr("Print the address from a LONG_MIN_VALUE and a LONG_MAX_VALUE: %p: ");
	count = ft_printf("%p %p", LONG_MIN, LONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the address from a INT_MIN_VALUE and a INT_MAX_VALUE: %p: ");
	count = ft_printf("%p %p", INT_MIN, INT_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the address from a ULONG_MIN_VALUE and a ULONG_MAX_VALUE: %p: ");
	count = ft_printf("%p %p", -ULONG_MAX, ULONG_MAX);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the address from a 0 and a 0: %p: ");
	count = ft_printf("%p %p", 0, 0);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;

	ft_putstr("Print the address from a 1 and a 1 %p: ");
	count = ft_printf("%p %p", 1, 1);
	ft_putstr("\ncharactere count = ");
	ft_putnbr(count);
	ft_putstr("\n\n");
	count = 0;
}


// 	// ft_printf("Print the MIN_VALUE number of an int: %d\n", INT_MIN);
// 	// printf("Print the MIN_VALUE number of an int from original printf: %d\n\n", INT_MIN);

// 	// ft_printf("Print the MAX_VALUE number of an int: %d\n", INT_MAX);
// 	// printf("Print the MAX_VALUE number of an int from original printf: %d\n\n", INT_MAX);

// 	// ft_printf("Print a single caractere: %c\n", 'c');
// 	// printf("Print a single caractere from original printf: %c\n\n", 'c');

// 	// ft_printf("Print a string: %s\n", "Test d'une chaine");
// 	// printf("Print a string from original printf: %s\n\n", "Test d'une chaine");

// 	// ft_printf("Print HEXA number with negative number: %X\n", -42);
// 	// printf("Print HEXA number with negative number from original printf: %X\n\n", -42);

// 	// ft_printf("Print HEXA number INT_MAX number: %X\n", INT_MAX);
// 	// printf("Print HEXA number INT_MAX number from original printf: %X\n\n", INT_MAX);

// 	// ft_printf("Print HEXA number INT_MIN number: %X\n", INT_MIN);
// 	// printf("Print HEXA number INT_MAX number from original printf: %x\n\n", INT_MIN);

// 	// ft_printf("Print hexa number with negative number: %X\n", -42);
// 	// printf("Print hexa number with negative number from original printf: %X\n\n", -42);

// 	// ft_printf("Print hexa number INT_MAX number: %X\n", INT_MAX);
// 	// printf("Print hexa number INT_MAX number from original printf: %X\n\n", INT_MAX);

// 	// ft_printf("Print hexa number INT_MIN number: %X\n", INT_MIN);
// 	// printf("Print HEXA number INT_MIN number from original printf: %x\n\n", INT_MIN);

// 	// ft_printf("Print pointeur address: %p\n", str);
// 	// printf("Print pointeur address from original printf: %p\n\n", str);
//}
*/
