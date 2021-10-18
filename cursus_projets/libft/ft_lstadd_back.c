/* Les paramètre de la fonction sont t_list **alst et t_list *new.

 * Le premier est un double pointeur, pusiqu'il fait reference au pointeur next du
 * dernier élément de la liste, soit le premier ajouté a la liste. L'un pointant
 * à l'adresse de l'élément et l'autre à l'adresse de sont pointeur *next.
 *
 * Le deuxième est un pointeur vers l'adresse du nouvelle élément que nous voulons ajouter.
 *
 * La fonction créé un pointeur intermédaire *first_element qui prend pour type la structure de notre liste sans plus.
 *
 * Esuite, avant de procéder à la manipulation des adresses, la fonction vérifie si *alst (alst->next)
 * est égale a NULL. Si il y vrai, cela voudrait dire que la liste est vide et que l'élément *new que nous voulons
 * ajouter peut y être insérer qu'en attribuant à sont pointeur *next la valeur NULL. Sinon, c'est
 * qu'il y a au moins un autre élément et devons alors attribuer l'adresse du premier élément de la liste
 * à l'aide de la fonction ft_lstlast() à notre pointeur intermédiaire.
 *
 * Pour finir, le pointeur *next
 * de l'élément pointé par *first_element, soit le dernier élément, prend l'adresse de la nouvelle élément.
 * Cela place maintenant ce dernier éléments derrière la nouvelle élément.
 *
 * Noter que le nouvelle élément point aussi vers NULL, pusique la fonction ft_lstnew() donne
 * au pointeur *next de l'élément la valeur NULL.
 * */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list  *first_element;

    if (alst || new)
    {
        if (*alst == NULL)
            *alst = new;
        else
        {
            first_element = ft_lstlast(*alst);
            first_element->next = new;
        }
    }
}
/*
#include <stdio.h>
int main(void)
{
	char	str1[] = "On en a";
	char	str2[] = "GROSSS!";

	t_list	*new_element;

	new_element = ft_lstnew((void *)str1);
	printf("Avant l'ajout du nouvelle élément:\n\n%s\n\n\n", new_element->content);

    ft_lstadd_back(&new_element->next, ft_lstnew((void *)str2));
    while (new_element->next != NULL)
    {
        printf("Après l'ajout du nouvelle élément:\n\n%s\n", new_element->content);
        new_element = new_element->next;
    }

    //printf("Après l'ajout du nouvelle élément:\n\n%s\n", new_element->content);
    printf("%s\n", new_element->content);
    return (0);
}
*/
/*
#include <stdio.h>
int main(void)
{
	char	str1[] = "On en a";
	char	str2[] = "GROSSS!";
    char    str3[] = "Sir Sir!!";
    char    str4[] = "HOO!!";

	t_list	*new_element;

	new_element = ft_lstnew((void *)str1);
	printf("Avant l'ajout du nouvelle élément:\n\n%s\n\n\n", new_element->content);

    ft_lstadd_back(&new_element->next, ft_lstnew((void *)str2));
    ft_lstadd_front(&new_element->next, ft_lstnew((void *)str3));
    ft_lstadd_front(&new_element->next, ft_lstnew((void *)str4));
    printf("Apres ajout de quelques éléments\n");
    while (new_element->next != NULL)
    {
        printf("%s\n", new_element->content);
        new_element = new_element->next;
    }

    //printf("Après l'ajout du nouvelle élément:\n\n%s\n", new_element->content);
    printf("%s\n", new_element->content);
    return (0);
}
*/
