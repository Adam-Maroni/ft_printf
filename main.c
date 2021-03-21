#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
#define TEST "|%*p|\n", 9, 0xc7e1ab0
	int nb = 0;
	int *p = &nb;
	//fflush(stdout);
	ft_printf("ftprintf: ");
	nb = ft_printf(TEST);
	printf("%d\n", nb);
	nb = printf(TEST);
	printf("%d\n", nb);
	
}
