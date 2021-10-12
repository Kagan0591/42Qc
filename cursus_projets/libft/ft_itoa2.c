
/* Alloue (avec malloc(3)) et retourne une chaine de
 * caractères représentant l’integer reçu en argument.
 * Les nombres négatifs doivent être gérés.
 * Valeur de retour est la chaine de caractères représentant l’integer.
 * NULL si l’allocation échoue. */

/* 1. Gerer les negatifs, une '-' devra etre present a str[0]
 * 2. Malloc avec une protection, Devra avoir une fonction pour
 * le nombre de chiffre.
*/
#include <stdio.h>
#include <stdlib.h>
static int numlen(int n)
{
    int count;

    count = 1;
    if (n < 0)
    {
        count++;
        n = n * -1;
    }
    while (n > 9)
    {
        n = n / 10;
        count++;
    }
    return (count);
}

char *ft_itoa(int n)
{
    char    *str;

    if (!(str = malloc(numlen(n) + 1)))
        return (0);
    if (n == -2147483648)
        return ("-2147483648");
    else if (n < 0)
    {
        str[0] = '-';
        n = n * -1;
    }
    *str = (numlen(n) + 1);
    str = '\0';
    while (n > 9)
    {
        *str-- = n % 10;
        n = n / 10;
    }
    *str = n;
    return (str);
}

int main(void)
{
    int     nbr = -12345;

    printf("%s\n", ft_itoa(nbr));
    return (0);
}
