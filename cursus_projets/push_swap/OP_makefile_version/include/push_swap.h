#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum
{
	false,
	true
}boolean;

typedef struct stack
{
	int				arg;
	struct stack	*next;
}stack;

// Prog functions
boolean	checkif_isdigit(char **argv);
boolean	checkif_repeated_number(char **argv);
stack	*push_argv_to_stk(int argc, char **argv, stack *p_stk);
stack	*swap_a(stack *p_stk);
void	push_a(stack **stk_a, stack **stk_b);
void	push_b(stack **stk_a, stack **stk_b);

// Stack functions
stack	*ft_stknew(int nbr);
stack	*ft_stkadd(stack *p_stk, int nbr);
boolean	ft_stk_isempty(stack *p_stk);
size_t	ft_stksize(stack *p_stk);
void	ft_print_stack(stack *p_stk);
stack	*ft_stkdelone(stack *p_stk);
stack	*ft_stkclear(stack *p_stk);

// Utils
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_isdigit(int c);

#endif
