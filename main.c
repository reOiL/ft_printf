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

	ft_printf("% +d", 0);
	//ft_printf("%010d\n", 124);
	//printf("%010d\n", 124);
	free(str);
	return (0);
}
