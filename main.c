#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
#define TEST "|%*.*i|\n", -2,3,8
	int nb = 0;
	int *p = &nb;
	fflush(stdout);
	ft_printf("ftprintf: ");
	nb = ft_printf(TEST);
	printf("%d\n", nb);
	nb = printf(TEST);
	printf("%d\n", nb);
	
}
