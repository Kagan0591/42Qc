#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

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
int	check_for_error(int argc, char **argv);
boolean	checkif_isdigit(char **argv);
boolean	checkif_isint(char **argv);
boolean	checkif_repeated_number(char **argv);
stack	*push_argv_to_stk(int argc, char **argv);
int		indexing_the_stack(stack *stack_a);

// Algo functions
stack	*swap_stkvalue_a(stack *p_stk);
stack	*swap_stkvalue_b(stack *p_stk);
void	push_to_a(stack **origin, stack **dest);
void	push_to_b(stack **origin, stack **dest);
stack	*rotate_a(stack *p_stk);
stack	*rotate_b(stack *p_stk);
stack	*reverse_rotate_a(stack *p_stk);
stack	*reverse_rotate_b(stack *p_stk);

// Algo quicksort
void	quicksort(stack *stack_a);
stack	*finding_pivot(stack *pt_to_stack_a);
void	swap_the_smaller_and_bigger(stack *stack_a, stack *pivot);
stack	*finding_bigger_than_pivot(stack *pt_to_stack_a, stack *pivot);
stack	*finding_smaller_than_pivot(stack *pt_to_stack_a, stack *pivot);

// Algo devide and conquer 1
void	sort_algo(stack **ptr_stack_a, stack **ptr_stk_b);
void	split_recursive(stack **stack_a, stack **stack_b);
void	split_stack(stack **ptr_stack_a, stack **ptr_stack_b);
int		search_and_return_the_smaller_nb_into_a(stack *stack_a);

// Stack functions
stack			*ft_stknew(int nbr);
stack			*ft_stkadd(stack *p_stk, int nbr);
boolean			ft_stk_isempty(stack *p_stk);
size_t			ft_stksize(stack *p_stk);
void			ft_print_stack(stack *p_stk);
stack			*ft_stkdelone(stack *p_stk);
stack			*ft_stkclear(stack *p_stk);

// Utils
int				ft_atoi(const char *str);
long long int	ft_atoll(const char *str);
void			ft_putstr(char *str);
void			ft_putnbr(int n);
void			ft_putchar(char c);
int				ft_isdigit(int c);

#endif
