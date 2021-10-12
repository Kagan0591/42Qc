/* 1. La fonction cree une chaine de char. La chaine est initialisee
 * avec malloc et prend la grandeur de la chaine s + 1 pour le '\0'.
 * 2. Cette meme chaine egale la valeur retournee de la chaine
 * passer en parametre de la fonction mystere f.
 * 3. Puis a chaine rst retournee
 *
 * Dans la foncition une protection pour malloc et si
 * la chaine s est vide est de mis */

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *sptr;
    size_t  i;

    if (!s)
        return (0);
    sptr = (char *)malloc((char *) * (ft_strlen(s) + 1));
    return (sptr);
}

char    *f(unsigned int, )

int main(void)
{
    char    *s1 = "Bonjour";
    char    *s2;

    s2 = ft_strmapi()
}
