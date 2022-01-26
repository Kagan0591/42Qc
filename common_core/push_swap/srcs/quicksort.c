/*

1. Choisir un pivot (pour ma part le dernier nombre de la liste)

	- positionner un pointeur sur le pivot sélectionné.


2. Comparer les nombres au pivot justqu'a trouver un plus grand.

	- Positionner un le pointeur (pt_high) sur le nombre trouvé.

3. Comparer les nombres au pivot, quand un plus petit est trouvé,

	- Interchanger ce nombre avec le plus grand trouvé plus tot (pt_high).

4.

*/
#include "push_swap.h"

void	quicksort(stack *stack_a)
{
	int	pivot;
	pivot = finding_pivot(&stack_a);
	ft_putstr("Le pivot est : ");
	ft_putnbr(pivot);
}
int	finding_pivot(stack **pt_to_stack_a)
{
	while ((*pt_to_stack_a)->next != NULL)
	{
		*pt_to_stack_a = (*pt_to_stack_a)->next;
	}
	return ((*pt_to_stack_a)->arg);
}