//
// Created by Johnny Webber on 26/10/2019.
//

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char 	*str;
	char 	c;

	c = '1';
	str = strdup("abcde");

	ft_printf("abcde%c   %s\n", c, str);
	printf("abcde%c   %s\n", c, str);
	ft_printf("%10.5d\n", 5);
	printf("%10.5d\n", 5);
	ft_printf("%0.0i\n", 9);
	printf("%0.0i", 9);
}
