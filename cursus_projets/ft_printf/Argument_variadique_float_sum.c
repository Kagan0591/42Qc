#include <stdio.h>
#include <stdarg.h>

double float_sum(int n, ...)
{
	va_list valist;
	double sum;
	int i;

	va_start(valist, n);
	sum = 0.0;
	i = 0;
	while (i < n)
	{
		sum += va_arg(valist, double);
		printf("TEST %f\n", sum);
		i++;
	}
	va_end(valist);
	return (sum);
}

int main(void)
{
	printf("la somme des arguments variadiques est de %.1f\n", float_sum(3, 4.5,5.5,7.6));
	return (0);
}
