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
    i.ll = 9223372036854775807 ;
    abc.type = 'x';
    abc.flags = FLAG_SHARP;
    abc.precision = 0;
    int a = put_nbr_base(i, abc, 16);
    ft_putendl("");
    int b = printf("%#llx\n", i.ll);
    printf("my = %i\norig = %i", a, b - 1);
    /*
    put_nbr_base(i, abc, 16);
    i.ull = 1;
    ft_putendl("");
    put_nbr_base(i, abc, 10);
    ft_putendl("");
    i.ull = 0;
    put_nbr_base(i, abc, 10);
    ft_putendl("");
    i.ll = -9223372036854775808;
    abc.type = '\0';
    put_nbr_base(i, abc, 10);
    ft_putendl("");
     */
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
