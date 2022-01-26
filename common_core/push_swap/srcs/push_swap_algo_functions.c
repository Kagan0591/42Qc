#include "push_swap.h"

stack	*swap_stkvalue_a(stack *p_stk)
{
	stack	*tmp;

	ft_putstr("sa\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

stack	*swap_stkvalue_b(stack *p_stk)
{
	stack	*tmp;

	ft_putstr("sb\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

void	push_to_a(stack **origin, stack **dest)
{
	stack	*tmp_orig;
	stack	*tmp_dest;

	ft_putstr("pa\n");
	if (origin && dest)
	{
		tmp_orig = (*origin)->next;
		tmp_dest = (*dest);
		*dest = *origin;
		(*dest)->next = tmp_dest;
		(*origin) = tmp_orig;
	}
}

void	push_to_b(stack **origin, stack **dest)
{
	stack	*tmp_orig;
	stack	*tmp_dest;

	ft_putstr("pb\n");
	if (origin && dest)
	{
		tmp_orig = (*origin)->next;
		tmp_dest = (*dest);
		*dest = *origin;
		(*dest)->next = tmp_dest;
		(*origin) = tmp_orig;
	}
}

stack	*rotate_a(stack *p_stk) // Put the last node to the top
{
	stack	*tmp;
	stack	*tmp_top;

	ft_putstr("ra\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		p_stk->next = tmp;
		return (tmp_top);
	}
	else
		return (p_stk);
}

stack	*rotate_b(stack *p_stk) // Put the last node to the top
{
	stack	*tmp;
	stack	*tmp_top;

	ft_putstr("rb\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		p_stk->next = tmp;
		return (tmp_top);
	}
	else
		return (p_stk);
}

stack	*reverse_rotate_a(stack *p_stk) // Put the first node to the buttom
{
	stack		*tmp;
	stack		*top_tmp;
	size_t		pos;

	ft_putstr("rra\n");
	if (ft_stksize(p_stk) >= 2)
	{
		pos = ft_stksize(p_stk);
		tmp = p_stk;
		while (pos > 2)
		{
			p_stk = p_stk->next;
			pos--;
		}
		top_tmp = p_stk->next;
		p_stk->next = NULL;
		top_tmp->next = tmp;
		return (top_tmp);
	}
	else
		return (p_stk);
}

stack	*reverse_rotate_b(stack *p_stk) // Put the first node to the buttom
{
	stack		*tmp;
	stack		*top_tmp;
	size_t		pos;

	ft_putstr("rrb\n");
	if (ft_stksize(p_stk) >= 2)
	{
		pos = ft_stksize(p_stk);
		tmp = p_stk;
		while (pos > 2)
		{
			p_stk = p_stk->next;
			pos--;
		}
		top_tmp = p_stk->next;
		p_stk->next = NULL;
		top_tmp->next = tmp;
		return (top_tmp);
	}
	else
		return (p_stk);
}
