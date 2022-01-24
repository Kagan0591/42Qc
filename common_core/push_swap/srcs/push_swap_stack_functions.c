#include "push_swap.h"

stack	*ft_stknew(int nbr)
{
	stack	*new_element;

	new_element = malloc(sizeof(stack));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = NULL;
	}
	return (new_element);
}

stack	*ft_stkadd(stack *p_stk, int nbr)
{
	stack	*new_element;

	if (!p_stk)
		p_stk = ft_stknew(nbr);
	new_element = malloc(sizeof(stack));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = p_stk;
	}
	return (new_element);
}

boolean 	ft_stk_isempty(stack *p_stk)
{
	if(p_stk == NULL)
		return (true);
	return (false);
}

size_t	ft_stksize(stack *p_stk)
{
	size_t	count;

	count = 0;
	while (p_stk)
	{
		count++;
		p_stk = p_stk->next;
	}
	return (count);
}

void	ft_print_stack(stack *p_stk)
{
	if (p_stk != NULL)
	{
		ft_putnbr(p_stk->arg);
		ft_print_stack(p_stk->next);
	}
}

stack	*ft_stkdelone(stack *p_stk)
{
	stack	*tmp;
	if (p_stk)
	{
		tmp = p_stk->next;
		free(p_stk);
		return (tmp);
	}
	return (NULL);
}

stack	*ft_stkclear(stack *p_stk)
{
	stack	*tmp;

	if(p_stk)
	{
		tmp = p_stk;
		while(tmp)
			tmp = ft_stkdelone(tmp);
		return (tmp);
	}
	return (p_stk);
}
