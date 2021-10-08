#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;

    if (needle[j] == '\0')
        return ((char *)&haystack[i]);
    while (haystack[i] != '\0' && i < len)
    {
        while (haystack[i + j] != '\0' && haystack[i + j] == needle[j] && (i + j) < len)
        {
            if (needle[j + 1] == '\0')
                return ((char *)&haystack[i]);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

int	main(void)
{
	char *haystack = "aaabcabcd";

	printf("%s\n", ft_strnstr(haystack, "abcd", 9));
	return (0);
}
