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

	//ft_printf("%-10c.%10c\n", 's', 's');
	//printf("%-10c.%10c\n", 's', 's');

	//int a = ft_printf("%5c  %-1.4s\n", '1', "abcde");
	//int b = printf("%5c  %-1.4s\n", '1', "abcde");

	//ft_printf("%p\n", &str);
	//printf("%p\n", &str);

	//int a = ft_printf("%-+25.15hd\n", 125656);
	//int b = printf("%-+25.15hd\n", 125656);

	//int a = ft_printf("%10d\n", -124);
	//int b = printf("%10d\n", -124);
	//printf("%d  %d\n", a, b);

	/*
	printf("%s", "width & precision\n");
	ft_printf("%10.5d %10.5d\n", -124, 124);
	ft_printf("%-10.5d %-10.5d\n", -124, 124);
	ft_printf("%+10.5d %+10.5d\n", -124, 124);
	ft_printf("%-+10.5d %-+10.5d\n", -124, 124);
	ft_printf("%+-10.5d %+-10.5d\n\n", -124, 124);
	printf("%10.5d %10.5d\n", -124, 124);
	printf("%-10.5d %-10.5d\n", -124, 124);
	printf("%+10.5d %+10.5d\n", -124, 124);
	printf("%-+10.5d %-+10.5d\n", -124, 124);
	printf("%+-10.5d %+-10.5d\n\n", -124, 124);

	printf("%s", "only precision\n");
	ft_printf("%.5d %.5d\n", -124, 124);
	ft_printf("%-.5d %-.5d\n", -124, 124);
	ft_printf("%+.5d %+.5d\n", -124, 124);
	ft_printf("%-+.5d %-+.5d\n", -124, 124);
	ft_printf("%+-.5d %+-.5d\n\n", -124, 124);
	printf("%.5d %.5d\n", -124, 124);
	printf("%-.5d %-.5d\n", -124, 124);
	printf("%+.5d %+.5d\n", -124, 124);
	printf("%-+.5d %-+.5d\n", -124, 124);
	printf("%+-.5d %+-.5d\n\n", -124, 124);

	printf("%s", "only width\n");
	ft_printf("%10d %10d\n", -124, 124);
	ft_printf("%-10d %-10d\n", -124, 124);
	ft_printf("%+10d %+10d\n", -124, 124);
	ft_printf("%-+10d %-+10d\n", -124, 124);
	ft_printf("%+-10d %+-10d\n\n", -124, 124);
	printf("%10d %10d\n", -124, 124);
	printf("%-10d %-10d\n", -124, 124);
	printf("%+10d %+10d\n", -124, 124);
	printf("%-+10d %-+10d\n", -124, 124);
	printf("%+-10d %+-10d\n\n", -124, 124);

	printf("%s", "nothing\n");
	ft_printf("%d %d\n", -124, 124);
	ft_printf("%-d %-d\n", -124, 124);
	ft_printf("%+d %+d\n", -124, 124);
	ft_printf("%-+d %-+d\n", -124, 124);
	ft_printf("%+-d %+-d\n\n", -124, 124);
	printf("%d %d\n", -124, 124);
	printf("%-d %-d\n", -124, 124);
	printf("%+d %+d\n", -124, 124);
	printf("%-+d %-+d\n", -124, 124);
	printf("%+-d %+-d\n\n", -124, 124);

	printf("%s", "space flag\n");
	ft_printf("% d % d\n", -124, 124);
	ft_printf("% 10d % 10d\n", -124, 124);
	ft_printf("% .5d % .5d\n", -124, 124);
	ft_printf("% 10.5d % 10.5d\n\n", -124, 124);
	printf("% d % d\n", -124, 124);
	printf("% 10d % 10d\n", -124, 124);
	printf("% .5d % .5d\n", -124, 124);
	printf("% 10.5d % 10.5d\n\n", -124, 124);
	*/
	/*
	printf("%s", "width & precision\n");
	ft_printf("%10.5x %10.5x\n", -124, 124);
	ft_printf("%-10.5x %-10.5x\n", -124, 124);
	ft_printf("%+10.5x %+10.5x\n", -124, 124);
	ft_printf("%-+10.5x %-+10.5x\n", -124, 124);
	ft_printf("%+-10.5x %+-10.5x\n\n", -124, 124);
	printf("%10.5x %10.5x\n", -124, 124);
	printf("%-10.5x %-10.5x\n", -124, 124);
	printf("%+10.5x %+10.5x\n", -124, 124);
	printf("%-+10.5x %-+10.5x\n", -124, 124);
	printf("%+-10.5x %+-10.5x\n\n", -124, 124);


	printf("%s", "only precision\n");
	ft_printf("%.5x %.5x\n", -124, 124);
	ft_printf("%-.5x %-.5x\n", -124, 124);
	ft_printf("%+.5x %+.5x\n", -124, 124);
	ft_printf("%-+.5x %-+.5x\n", -124, 124);
	ft_printf("%+-.5x %+-.5x\n\n", -124, 124);
	printf("%.5x %.5x\n", -124, 124);
	printf("%-.5x %-.5x\n", -124, 124);
	printf("%+.5x %+.5x\n", -124, 124);
	printf("%-+.5x %-+.5x\n", -124, 124);
	printf("%+-.5x %+-.5x\n\n", -124, 124);

	printf("%s", "only width\n");
	ft_printf("%10x %10x\n", -124, 124);
	ft_printf("%-10x %-10x\n", -124, 124);
	ft_printf("%+10x %+10x\n", -124, 124);
	ft_printf("%-+10x %-+10x\n", -124, 124);
	ft_printf("%+-10x %+-10x\n\n", -124, 124);
	printf("%10x %10x\n", -124, 124);
	printf("%-10x %-10x\n", -124, 124);
	printf("%+10x %+10x\n", -124, 124);
	printf("%-+10x %-+10x\n", -124, 124);
	printf("%+-10x %+-10x\n\n", -124, 124);

	printf("%s", "nothing\n");
	ft_printf("%x %x\n", -124, 124);
	ft_printf("%-x %-x\n", -124, 124);
	ft_printf("%+x %+x\n", -124, 124);
	ft_printf("%-+x %-+x\n", -124, 124);
	ft_printf("%+-x %+-x\n\n", -124, 124);
	printf("%x %x\n", -124, 124);
	printf("%-x %-x\n", -124, 124);
	printf("%+x %+x\n", -124, 124);
	printf("%-+x %-+x\n", -124, 124);
	printf("%+-x %+-x\n\n", -124, 124);

	printf("%s", "space flag\n");
	ft_printf("% x % x\n", -124, 124);
	ft_printf("% 10x % 10x\n", -124, 124);
	ft_printf("% .5x % .5x\n", -124, 124);
	ft_printf("% 10.5x % 10.5x\n\n", -124, 124);
	printf("% x % x\n", -124, 124);
	printf("% 10x % 10x\n", -124, 124);
	printf("% .5x % .5x\n", -124, 124);
	printf("% 10.5x % 10.5x\n\n", -124, 124);
	*/
	/*
	printf("%s", "space flag\n");
	ft_printf("% u % u\n", -124, 124);
	ft_printf("% 10u % 10u\n", -124, 124);
	ft_printf("% .5u % .5u\n", -124, 124);
	ft_printf("% 10.5u % 10.5u\n", -124, 124);
	ft_printf("%# u %# u\n", -124, 124);
	ft_printf("%0 u %0 u\n\n", -124, 124);
	printf("% u % u\n", -124, 124);
	printf("% 10u % 10u\n", -124, 124);
	printf("% .5u % .5u\n", -124, 124);
	printf("% 10.5u % 10.5u\n", -124, 124);
	printf("%# u %# u\n", -124, 124);
	printf("%0 u %0 u\n", -124, 124);
	 */
	/*
	ft_printf("%f\n", 1.1234);
	printf("%f\n", 1.1234);
	ft_printf("%f\n", 0.1234);
	printf("%f\n", 0.1234);
	ft_printf("%f\n", 1447432.1234);
	printf("%f\n", 1447432.1234);
	ft_printf("%f\n", 1447432.123456);
	printf("%f\n", 1447432.123456);
	ft_printf("%f\n", 1447432.123456789);
	printf("%f\n", 1447432.123456789);
	ft_printf("%.8f\n", 1447432.123456789);
	printf("%.8f\n", 1447432.123456789);
	ft_printf("%.0f\n", 1447432.123456789);
	printf("%f\n", 1447432.123456789);
	ft_printf("%f\n", -1447432.123456789);
	printf("%f\n", -1447432.123456789);
	*/
	ft_printf("%20f\n", -1447432.123456789);
	printf("%20f\n", -1447432.123456789);
	ft_printf("%-20f\n", -1447432.123456789);
	printf("%-20f\n", -1447432.123456789);
	ft_printf("% f\n", -1447432.123456789);
	printf("% f\n", -1447432.123456789);
	ft_printf("%+f\n", 1447432.123456789);
	printf("%+f\n", 1447432.123456789);
	ft_printf("%+Lf\n", (long double)(1e+37) + 1);
	printf("%+Lf\n", (long double)(1e+37) + 1);
	free(str);
	return (0);
}