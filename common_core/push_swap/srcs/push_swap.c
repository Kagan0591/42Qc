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

// radix sort si j arrive pas a faire moi memm un algo, ile est performant et facile a implementer

int	main (int argc, char **argv)
{
	node	*stk_a;
//	stack	*stk_b;
//	int		*stack_index;
	int	*stk_a_sorted;
	int i;
//	stk_b = NULL;

	// ------------ Print the nbr of arg(s)
	// ft_printf("Le nombre d'argument passé est de %i incluant le nom du programme\n", argc);
	ft_putstr("Le nombre d'argument passé, incluant le nom du programme, est de: ");
	ft_putnbr(argc);
	ft_putstr("\n\n");
	// ------------ Add the data from argv to stk_a
	if (check_for_error(argc - 1, argv) == 0)
		return (0);
	stk_a = push_argv_to_stk(argc - 1, argv);
	stk_a_sorted = counting_sort_0to9(stk_a);
	i = 0;
	ft_putnbr(i);
	while (i < 5)
	{
		ft_putnbr(stk_a_sorted[i]);
		i++;
	}
//	stack_index = indexing_the_stack(stk_a);

	ft_putstr("\n\nEND OF PROGRAM\n");

	//quicksort(stk_a);
	return (1);
}

int	*indexing_the_stack(node *stack_a)
{
	int		count;
	node	*start_of_stack_a;
	node	*stack_a_tmp;
	int		*indexed_stack;
	int		i;

	indexed_stack = malloc(sizeof(int) * ft_stksize(stack_a));
	i = 0;
	start_of_stack_a = stack_a;
	while (stack_a->next != NULL)
	{
		count = 0;
		stack_a_tmp = start_of_stack_a;
		while (stack_a_tmp != NULL)
		{
			if (stack_a->arg > stack_a_tmp->arg)
				count++;
			stack_a_tmp = stack_a_tmp->next;
		}
		stack_a = stack_a->next;
		indexed_stack[i] = count;
		i++;
		//ft_putnbr(i);
	}
	i = 0;
	while (i <= 3)
	{
		ft_putnbr(indexed_stack[i]);
		i++;
	}
	return (indexed_stack);
}

int	check_for_error(int argc, char **argv)
{
	// ------------ Check if the args are all integrer
	if (checkif_isint(argv) == false)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	// ------------ Check if the args are all number
	if (checkif_isdigit(argv) == false)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	// ------------ Check if none of the number are repeated.
	if (checkif_repeated_number(argv) == true)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 0)
		return (0);
	return (1);
}


// stack	small_sort(stack stack_b)
// {

// }

// stack	big_sort(stack stack_a)
// {

// }

/* Une fonction pour placer chaques arguments dans une structure
 * en pile */

// stack	*push_argv_to_stk(char **argv)
// {
// 	stack	*stack_a;
// 	int		i;

// 	stack_a = ft_stknew(atoi(argv[1]));
// 	i = 2;
// 	while (argv[i])
// 	{
// 		stack_a = ft_stkadd(stack_a, atoi(argv[i]));
// 		i++;
// 	}
// 	return (stack_a);
// }

node	*push_argv_to_stk(int argc, char **argv)
{
	node	*stack_a;

	stack_a = ft_stknew(atoi(argv[argc]));
	argc = (argc -1);
	while (argc >= 1)
	{
		stack_a = ft_stkadd(stack_a, atoi(argv[argc]));
		argc--;
	}
	return (stack_a);
}


/* Une fonction pour vérifier si il s'agit bien d'un chiffre pour
 * chaques arguments vector (argv) */

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

/* Une fonction pour vérifier si il s'agit bien d'un integrer pour
 * chaques arguments vector (argv) */

boolean	checkif_isint(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) < -2147483648 || ft_atoll(argv[i]) > 2147483647)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

/* Une fonction pour vérifier si il n y a pas de doublon pour
 * chaques arguments vector (argv) */

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
