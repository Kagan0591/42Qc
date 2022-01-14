#include "push_swap.h"

/* L'algorithme Quick Sort est le plus éfficace pour le tri de petites
 * quantités de données. Il est préferé pour les tableaux.
 *
 * 1. Le tableau d'éléments est divisé en plusieurs parties jusqu'à ce
 * qu'il ne soit plus possible de le diviser davantage.
 *
 * 2. Il utilise un élément clé (un pivot) pour partitionner les éléments.
 * Ainsi, Une partition de gauche contient tous les éléments qui sont
 * plus petits que le pivot et une partition de droite contient tous
 * les éléments qui sont plus grands que l'élément clé.
 *
 * 3. Les éléments sont divisés en deux sous-tableaux (n/2) encore et encore
 * jusqu'à ce qu'il ne reste qu'un seul élément.
 * */




/* L'algorithme Merge Sort est très éfficace pour le tri de grandes
 * quantités de données. Il est préferé pour les listes chainées.
 *
 * 1. Les éléments sont divisés en deux sous-tableaux (n/2) encore et encore
 * jusqu'à ce qu'il ne reste qu'un seul élément.
 *
 * 2.Le tri par fusion utilise de l espace stockage supplémentaire
 * pour trier les tableaux auxiliaires.
 *
 * 3. Le tri par fusion utilise trois tableaux, où deux sont utilisés
 * pour stocker chaque moitié, et le troisième, externe, est utilisé
 * pour stocker la liste triée finale en fusionnant les deux autres
 * et chaque tableau est ensuite trié de manière récursive. Donc, tant
 * qu'il peut etre divisé, le tableau sera récursivement divisé.
 *
 * 4. Enfin, tous les sous-tableaux sont fusionnés pour ne faire qu'un
 * tableau de « n » taille d'élément.*/



int	main (int argc, char **argv)
{
	stack	*stk_a;
	stack	*stk_b;

	// ------------ Check if at least one arg are given
	if (argc == 1)
	{
		ft_putstr("Aucun argument n'est donné\n");
		return (0);
	}

	// ------------ Check if the args are all number
	if (checkif_isdigit(argv) == false)
	{
		ft_putstr("Attention: Il y a un au moins un des arguments qui n est pas un nombre\n");
		return (0);
	}

	// ------------ Check if only one arg are given. In this case, no need to sort
	if (argc == 2)
	{
		ft_putstr(argv[1]);
		ft_putstr("\n");
		return (0);
	}

	// ------------ Print the nbr of arg(s)
	// ft_printf("Le nombre d'argument passé est de %i incluant le nom du programme\n", argc);
	ft_putstr("Le nombre d'argument passé, incluant le nom du programme, est de: ");
	ft_putnbr(argc);
	ft_putstr("\n\n");

	// ------------ Check if none of the number are repeated.
	if (checkif_repeated_number(argv) == true)
	{
		ft_putstr("Attention: Il y a au moins un nombre qui se repete\n");
		return (0);
	}

	// ------------ Add the data from argv to stk_a
	stk_a = push_argv_to_stk(argc - 1, argv, stk_a);
	ft_print_stack(stk_a);
	ft_putstr("\n");
	stk_a = swap_a(stk_a);
	ft_print_stack(stk_a);
	ft_putstr("\n");
	push_b(&stk_a, &stk_b);
	ft_putstr("\nTEST\n");
	ft_print_stack(stk_a);
	ft_putstr("\n");
	ft_print_stack(stk_b);
	ft_putstr("\n");
	ft_putstr("\nTEST\n");
	stk_a = ft_stkclear(stk_a);
	ft_print_stack(stk_a);
	ft_putstr("\n");
	ft_putstr("FIN\n");
	// stk_a = ft_stkdelone(stk_a);
	// ft_print_stack(stk_a);
	// ft_putstr("\n");
	// stk_a = ft_stkdelone(stk_a);
	// ft_print_stack(stk_a);
	// ft_putstr("\n");
	// stk_a = ft_stkdelone(stk_a);
	// ft_print_stack(stk_a);
	// ft_putstr("\n");

	return (1);
}

stack	*push_argv_to_stk(int argc, char **argv, stack *p_stk)
{
	int	i;

	p_stk = ft_stknew(atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		p_stk = ft_stkadd(p_stk, atoi(argv[i]));
		i++;
	}
	return (p_stk);
}

// if (last est plus petit que first)
// 	somithing append like swap_a

// void	swap_a(stack stk_a)
// {

// }


/* Une fonction pour vérifier si il s'agit bien d'un chiffre pour
 * chaques arguments vector (argv)*/

boolean	checkif_isdigit(char **argv)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (false);
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

boolean	checkif_repeated_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;

	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv [i]) == ft_atoi(argv[j]))
				return (true);
			j++;
		}
		i++;
		j = (i + 1);
	}
	return (false);
}

stack	*swap_a(stack *p_stk)
{
	stack	*tmp;

	if (ft_stksize(p_stk) >= 2)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

void	push_a(stack **stk_a, stack **stk_b)
{
	stack	*tmp;

	if (stk_b)
	{
		tmp = (*stk_b)->next;
		(*stk_b)->next = *stk_a;
		(*stk_b) = tmp;
	}
}

void	push_b(stack **stk_a, stack **stk_b)
{
	stack	*tmp_a;
	stack	*tmp_b;

	if (stk_a)
	{
		tmp_a = (*stk_a)->next;
		if (!stk_b)
			stk_b = NULL;
		tmp_b = (*stk_b);
		*stk_b = *stk_a;
		(*stk_b)->next = tmp_b;
		(*stk_a) = tmp_a;
	}
}
