/* Libère la mémoire de l’élément passé en argument en utilisant la fonction del puis avec free(3).
 * La mémoire de next ne doit pas être free.
 *
 * Prototypes:
 * #1. L’élement à free
 * #2. L’adresse de la fonction permettant de supprimer le contenu de l’élement. */
#include "libft.h"

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (lst)
    {
        del(lst->content);
        free(lst);
    }
}
