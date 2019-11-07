//
// Created by Johnny Webber on 26/10/2019.
//

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>


void dummy(char *mask, ...)
{
    va_list	args;
    t_format abc;
    va_start(args, mask);
    print_float(abc, args);
    va_end(args);
}

int main()
{
	//char 	*str;
	//char 	c;

	//c = '1';
	//str = strdup("abcde");
	//ft_printf("abcde\n%c%s", c, str);
    //int d1=123, d2=42, d3=1543;
    //ft_printf("%#d", 1337);
    dummy("%f", 1.2);
}
