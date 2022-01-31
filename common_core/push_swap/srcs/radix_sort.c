#include "push_swap.h"
/*
void	radix_sort(void)
{

}

*/
void	counting_sort_0to9(stack *unsort_nbr)
{
	stack	*pt_beginstk_of_unsort_nbr;
	int	counting_tab[9]; // This tab have 10 slots, one for each number (0 to 9). each slot have the sum of same number from the stack
	int	*sorted_nbr;
	int	i;

	i = 0;
	while (i < 10)
	{
		counting_tab[i] = 0;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		while (unsort_nbr != NULL)
		{
			if (unsort_nbr->arg == i)
				counting_tab[i] = counting_tab[i] + 1; // Increment of 1 when finding corresponding number
			unsort_nbr = unsort_nbr->next; // Increment into the stack
		}
		unsort_nbr = pt_beginstk_of_unsort_nbr; // restore the stack from begining to repeate the process for each num
		i++;
	}
	i = 0;
	while (i < 9)
	{
		counting_tab[i + 1] = (counting_tab[i] + counting_tab[i + 1]);
		i++;
	}
	i = 0;
	sorted_nbr = calloc((ft_stksize(pt_beginstk_of_unsort_nbr) - 1), sizeof(int));
	while (unsort_nbr != NULL)
	{
		sorted_nbr[counting_tab[unsort_nbr->arg] - 1] = unsort_nbr->arg;
		counting_tab[unsort_nbr->arg] = counting_tab[unsort_nbr->arg] - 1;
		unsort_nbr = unsort_nbr->next;
	}
}

/*
exemple de table :
no-t	t-un	t-diz
10		10		10
14		20		14
25		52		20
52		14		25
20		25		49
49		49		52
*/
