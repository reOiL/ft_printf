//
// Created by Johnny Webber on 26/10/2019.
//

#include "ft_printf.h"
#include <stdio.h>

#define PRINTF_STR "%i%d%d%s\n"
#define PRINTF_ARG 1337, -1337, 0, "abc"

int main()
{

	ft_printf(PRINTF_STR, PRINTF_ARG);
	printf(PRINTF_STR, PRINTF_ARG);
}