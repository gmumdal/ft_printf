#include "ft_printf.h"

int	main(void)
{
	int	i = ft_printf("ft : %10m\n");
	int	j = printf("nr : %10m\n");
	printf("%d\n", i);
	printf("%d\n", j);
}
