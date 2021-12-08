#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_print
{
	va_list	valist; // Les arguments a imprimer
	int	count; // La valeur de retour de ft_printf
}t_print;


int ft_printf(const char *, ...);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
void	ft_putstr(char *str);

#endif
