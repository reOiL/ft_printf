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
    printf("\n");
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
    t_format abc;
    t_integers i;
    i.ll = 15;
    put_nbr_base(i, abc, 10);
    put_nbr_base(i, abc, 16);
    /*
    parse_float(1E+37f);
    parse_float(0.15625f);
    parse_float(5.f);
    parse_float(2.5f);
    parse_float(1.2f);
    parse_float(0);
    parse_float(-1.2f);

    printf("%f\n", 1.2);
    dummy("%f", 1.2);

    printf("%f\n", 0.2);
    dummy("%f", 0.2);

    printf("%f\n", 0.f);
    dummy("%f", 0.f);


    printf("%f\n", 0.123456f);
    dummy("%f", 0.123456f);

    printf("%f\n", 0.123456789f);
    dummy("%f", 0.123456789f);

    printf("%f\n", 0.1234567f);
    dummy("%f", 0.1234567f);

    printf("%f\n", 12345.12345f);
    dummy("%f", 12345.12345f);

    printf("%f\n", 1E+37);
    dummy("%f", 1E+37);
     */
}
