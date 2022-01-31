#include "algo.h"

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if ((nbr / 10) != 0)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

s_stack	*ft_stknew(int nbr)
{
	s_stack	*new_element;

	new_element = malloc(sizeof(s_stack));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = NULL;
	}
	return (new_element);
}

s_stack	*ft_stkadd(s_stack *p_stk, int nbr)
{
	s_stack	*new_element;

	if (!p_stk)
		p_stk = ft_stknew(nbr);
	new_element = malloc(sizeof(s_stack));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = p_stk;
	}
	return (new_element);
}

int	ft_stksize(s_stack *p_stk)
{
	int	count;

	count = 0;
	while (p_stk)
	{
		count++;
		p_stk = p_stk->next;
	}
	return (count);
}

s_stack	*ft_stkdelone(s_stack *p_stk)
{
	s_stack	*tmp;
	if (p_stk)
	{
		tmp = p_stk->next;
		free(p_stk);
		return (tmp);
	}
	return (NULL);
}

s_stack	*ft_stkclear(s_stack *p_stk)
{
	s_stack	*tmp;

	if(p_stk)
	{
		tmp = p_stk;
		while(tmp)
			tmp = ft_stkdelone(tmp);
		return (tmp);
	}
	return (p_stk);
}
