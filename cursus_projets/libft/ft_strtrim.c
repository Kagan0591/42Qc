/* Les char dans le set ne doivent pas ce retrouver en debut et fin de phrase
 * Tant qu un des char est egale a la position de la string il doit etre retire
 * La fonction retournera la string sans ses characteres */

// Une fonction pour verifier les char en debut de phrase apelle de la fonction ft_strchr inverse
#include <stdio.h>
#include "libft.h"
size_t getstart(const char *s, const char *set)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
    {
        if (ft_strchr(set, s[i]) == NULL)
            break;
        i++;
    }
    return (i);
}

size_t  getend(const char *s, const char *set)
{
    size_t  i;
    size_t  count;

    i = ft_strlen(s) - 1;
    count = 0;
   // printf("GETEND A %zu\n", i);
    while (i > 0)
    {
        if (ft_strchr(set, s[i]) == 0)
            break;
        i--;
        count++;
       // printf("GETEND B %zu\n", i);
       // printf("GETEND C %zu\n", count);
    }
    return (count);
}
char	*ft_strtrim(const char *s1, const char *set)
{
    char    *s2;

    if (getstart(s1, set) >= ft_strlen(s1))
        return (0);
    s2 = ft_substr(s1, getstart(s1, set), (ft_strlen(s1) - getstart(s1, set) - getend(s1, set)));
    return (s2);
}
/*
int main(void)
{
    char    *s2;
    char    *s1 = "a";
    char    *set = "";

   // printf("%zu\n", getstart("bonjour", "bor"));
   // printf("%zu\n", getend("bonjour", "bor"));
    printf("%zu\n", getend(s1, set));
    printf("%zu\n", getstart(s1, set));
    s2 = ft_strtrim(s1, set);
    printf("%s\n", s2);
    return (0);
}
*/
// Unn fonction pour verifier les char en fin de phrase


// Fonction principal appel de la fonction ft_substr pour copie ft_substr(char const *s, unsigned int start, size_t len)
/*
char	*ft_strtrim(const char *s1, const char *set)
{

}
*/
