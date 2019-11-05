//
// Created by Johnny Webber on 26/10/2019.
//

#include "ft_printf.h"
#include <stdio.h>

#define PRINTF_STR "%i%d%d%s\n"
#define PRINTF_ARG 1337, -1337, 0, "abc"

int main()
{

	printf("ft_printf\t\tout -> ");
	printf("ft_printf\t\t=\t%i\n", ft_printf(PRINTF_STR, PRINTF_ARG));
	printf("printf\t\t\tout -> ");
	printf("printf\t\t\t=\t%i\n", printf(PRINTF_STR, PRINTF_ARG));
}