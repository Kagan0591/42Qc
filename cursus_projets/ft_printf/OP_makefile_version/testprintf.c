#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	count;

	count = printf("%u", -42);
	printf("\n\n%d\n", count);
	return (0);
}
