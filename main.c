//
// Created by Johnny Webber on 26/10/2019.
//

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char 	*str;
	str = strdup("abcde");
	ft_printf("%+*d\n", 5, 42);
	printf("{%*d}", -5, 42);
	free(str);
	return (0);
}