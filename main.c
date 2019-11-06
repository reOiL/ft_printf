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

	//ft_printf("abcde%c   %s    %10.5d,  %10.2d\n", c, str, 6, 125);
	printf("abcde%c   %s    %10.5d,  %10.2d\n", c, str, 6, 125);
	//printf("abcde%c   %s\n", c, str);
	//ft_printf("%10.5d\n", 5);
	//printf("%10.5d\n", 5);
	//printf("%lli", 235225227);
	//printf("%lld", 235225227);
	printf("%hhu", 256);
}
