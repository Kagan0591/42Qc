
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
#include "libft.h"

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
    int     i;

    i = 0;
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    if (!(str = malloc(numlen(n) + 1)))
        return (0);
    i = (numlen(n));
    if (n < 0)
    {
        str[0] = '-';
        n = n * -1;
    }
    //i = (numlen(n) + 1);
    str[i--] = '\0';
    while (n > 9)
    {
        str[i--] = (n % 10) + 48;
        n = n / 10;
    }
    str[i] = n + 48;
    return (str);
}
/*
int main(void)
{
    int     nbr = -2147483648;
    printf("La valeur int min devrait etre -2147483648, La fonction retourne:\n");
    printf("%s\n\n", ft_itoa(nbr));
    nbr = 2147483647;
    printf("La valeur int max devrait etre 2147483647, La fonction retourne:\n");
    printf("%s\n\n", ft_itoa(nbr));
    nbr = -1234;
    printf("La valeur tester est -1234, La fonction retourne:\n");
    printf("%s\n", ft_itoa(nbr));
    nbr = 1234;
    printf("La valeur tester est 1234, La fonction retourne:\n");
    printf("%s\n", ft_itoa(nbr));
    return (0);
}

*/
// La fonction bug avec les int positif pas d<affichage ...
