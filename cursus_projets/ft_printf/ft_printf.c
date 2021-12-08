#include "ft_printf.h"

void	type_selector(const char *str, t_print *p_data, int i)
{
	if (str[i] == 'd')
		ft_putstr(ft_itoa(p_data->valist));
}


int	ft_printf(const char *str, ...)
{
	t_print	*data;
	int	i;

	data = (t_print *) malloc(sizeof(t_print));
	if (!data)
		return (-1);
	va_start(data->valist, str);
	i = 0;
	data->count = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		data->count++;
		if (str[i] == '%')
		{
			i++;
			data->count++;
			type_selector(str, data, i);
		}
	}

	return (data->count);
}

int	main(void)
{
	ft_printf("Bonjour");
	return (0);
}
