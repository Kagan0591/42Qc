#include "libft.h"
#include <stdio.h>
/*
static int  numlen(int n)
{
    size_t  countnbr;

    countnbr = 1;
    if (n < 0)
        n = n * -1;
    while (n > 9)
    {
        n = (n / 10);
        countnbr = countnbr * 10;
    }
    return (countnbr);
}

#include <stdio.h>
void ft_putnbr_fd(int n, int fd)
{
    int lenght;

    lenght = 0;
    if (n == 0)
        ft_putchar_fd(0 + 48, fd);
    else if (n == -2147483648)
        ft_putstr_fd("-2147483648", fd);
    else if (n)
    {
        if (n < 0)
        {
            ft_putchar_fd('-', fd);
            n *= -1;
        }
       lenght = numlen(n);
        while (lenght > 9)
        {
            lenght = numlen(n);
            printf("LENGHT = %d\n\n", lenght);
            printf("FT_PUTCHAR_FD VALUE %d\n", (n / lenght));
            ft_putchar_fd((n / lenght) + 48, fd);
            if (n > 9)
                n = n % lenght;
            printf("%d\n\n", n);
        }
    }
}
*/
/* RECURSIVE */
void ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n *= -1;
    }
    while (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
      //  printf("%d\n", n);
        ft_putnbr_fd(n % 10, fd);
    }
    printf("%d\n", n);
    ft_putchar_fd(n, fd);
}


int main (void)
{
    ft_putnbr_fd(9234, 10);
}

