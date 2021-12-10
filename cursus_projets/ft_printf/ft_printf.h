/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:11:59 by tchalifo          #+#    #+#             */
/*   Updated: 2021/12/08 14:42:45 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_print
{
	va_list	valist; // Les arguments a imprimer
	int	count; // La valeur de retour de ft_printf
	int	i;
}t_print;


int		ft_printf(const char *, ...);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_itoa(long n);
int	ft_putstr(char *str);
void	ft_putnbr(int n);

#endif
