#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (count + 6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = ft_numlen(n);
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if ((n / 10) != 0)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
	return (count);
}

unsigned int	ft_putnbr_unsigned(unsigned int n)
{
	int count;

	count = ft_unsigned_numlen(n);
	if ((n / 10) != 0)
		ft_putnbr_unsigned(n / 10);
	ft_putchar((n % 10) + 48);
	return (count);
}

unsigned int	ft_putnbr_Hexa(unsigned int n)
{
	unsigned int	count;

	count = ft_hexa_numlen(n);
	if ((n / 16) != 0)
		ft_putnbr_Hexa(n / 16);
	if ((n % 16) > 9)
	 	ft_putchar((n % 16) + 55);
	else
		ft_putchar((n % 16) + 48);
	return (count);
}

unsigned int	ft_putnbr_hexa(unsigned int n)
{
	unsigned int	count;

	count = ft_hexa_numlen(n);
	if ((n / 16) != 0)
		ft_putnbr_hexa(n / 16);
	if ((n % 16) > 9)
	 	ft_putchar((n % 16) + 87);
	else
		ft_putchar((n % 16) + 48);
	return (count);
}

unsigned int	ft_putnbr_long_hexa(unsigned long n)
{
	unsigned int	count;

	count = ft_hexa_long_numlen(n);
	if ((n / 16) != 0)
		ft_putnbr_long_hexa(n / 16);
	if ((n % 16) > 9)
	 	ft_putchar((n % 16) + 87);
	else
		ft_putchar((n % 16) + 48);
	return (count);
}

unsigned int	ft_putmem(void *mem)
{
	unsigned int	count;

	if (!mem || mem == 0)
		return (write(1, "0x0", 3));
	ft_putstr("0x");
	count = 2;
	count = count + ft_putnbr_long_hexa((unsigned long) mem);
	return (count);
}

int	ft_numlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_unsigned_numlen(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_hexa_numlen(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 15)
	{
		n /= 16;
		count++;
	}
	count++;
	return (count);
}

int	ft_hexa_long_numlen(unsigned long n)
{
	int	count;

	count = 0;
	while (n > 15)
	{
		n /= 16;
		count++;
	}
	count++;
	return (count);
}
