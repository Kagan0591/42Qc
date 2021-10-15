#include "libft.h"

int ft_lstsize(t_list *lst)
{
    size_t  count_element;

    count_element = 0;
    while (lst!= 0)
    {
        count_element++;
        lst = (*lst).next;
    }
    return (count_element);
}
