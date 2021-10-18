/* Supprime et libère la mémoire de l’élément passé en paramètre, et de tous
 * les élements qui suivent, à l’aide de del et de free(3). Enfin,
 * le pointeur initial doit être mis à NULL.
 *
 * Protoypes:
 * #1. L’adresse du pointeur vers un élément.
 * #2. L’adresse de la fonction permettant de supprimer le contenu d’un élément.
 *
 * La fonction déclare
 * */

#include"libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *tmp;

    if (lst)
    {
        while(*lst)
        {
            tmp = (*lst)->next;
            ft_lstdelone((*lst), del);
            (*lst) = tmp;
        }
    }
}
