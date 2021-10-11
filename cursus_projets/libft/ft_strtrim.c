
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
    char    *s2;
    size_t  size;

    size = 0;
    if (!s1)
        return (NULL);
    if (!set)
        return (NULL);
    while (*s1 && ft_strchr(set, *s1))
        s1++;
    size = ft_strlen(s1);
    while (size && ft_strchr(set, s1[size]))
        size--;
    s2 = ft_substr(s1, 0, size + 1);
    return (s2);
}


#include <stdio.h>
#include <string.h>

int main(void)
{
    char    *s2;
    char    *s1 = "";
    char    *set = "";

    s2 = ft_strtrim(s1, set);
    printf("Comparaison %d\n", strcmp(s2, ""));
    printf("%s\n", s2);
    return (0);
}

