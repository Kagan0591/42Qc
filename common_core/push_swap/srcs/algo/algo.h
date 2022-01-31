#ifndef ALGO
#define ALGO

#include <stdlib.h>
#include <unistd.h>

typedef struct t_stack
{
	int				arg;
	struct t_stack	*next;
}s_stack;

int			*counting_sort_0to9_tab(int *unsort_nbr, int size);
int			*counting_sort_0to9_stk(s_stack *unsort_nbr);

//	For testing (including main function)
void		ft_putstr(char *str);
void		ft_putnbr(int n);
void		ft_putchar(char c);
s_stack		*ft_stknew(int nbr);
s_stack		*ft_stkadd(s_stack *p_stk, int nbr);
int			ft_stksize(s_stack *p_stk);
s_stack		*ft_stkdelone(s_stack *p_stk);
s_stack		*ft_stkclear(s_stack *p_stk);


#endif
