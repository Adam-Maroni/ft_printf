#include <stdio.h>
#include <stdlib.h>
#include "./ft_printf.h"
#define TEST "|%5%|\n"

int main(void)
{
	int nb = 0;
	nb = ft_printf(TEST);
	ft_printf("%d\n", nb);
	nb = printf(TEST);
	printf("%d\n", nb);
	return (0);
}
