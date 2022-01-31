#include "push_swap.h"

node	*ft_stknew(int nbr)
{
	node	*new_element;

	new_element = malloc(sizeof(node));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = NULL;
	}
	return (new_element);
}

node	*ft_stkadd(node *p_stk, int nbr)
{
	node	*new_element;

	if (!p_stk)
		return (ft_stknew(nbr));
	new_element = malloc(sizeof(node));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = p_stk;
	}
	return (new_element);
}

boolean 	ft_stk_isempty(node *p_stk)
{
	if(p_stk == NULL)
		return (true);
	return (false);
}

int	ft_stksize(node *p_stk)
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

void	ft_print_stack(node *p_stk)
{
	if (p_stk != NULL)
	{
		ft_putnbr(p_stk->arg);
		ft_print_stack(p_stk->next);
	}
}

node	*ft_stkdelone(node *p_stk)
{
	node	*tmp;
	if (p_stk)
	{
		tmp = p_stk->next;
		free(p_stk);
		return (tmp);
	}
	return (NULL);
}

node	*ft_stkclear(node *p_stk)
{
	node	*tmp;

	if(p_stk)
	{
		tmp = p_stk;
		while(tmp)
			tmp = ft_stkdelone(tmp);
		return (tmp);
	}
	return (p_stk);
}

//node	ft_stkclear_recursive(node stk)