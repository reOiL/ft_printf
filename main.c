//
// Created by Johnny Webber on 26/10/2019.
//

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define PRINTF_TEST(str, ...) \
    assert(ft_printf(str, __VA_ARGS__) == printf(str, __VA_ARGS__)); \

void test()
{
    int a, b, c;

    PRINTF_TEST("%d\n", 1337);
    PRINTF_TEST("%d\n", 1);
    PRINTF_TEST("%d\n", 0);
    PRINTF_TEST("%d\n", -1);
    PRINTF_TEST("%d\n", 2147483647);
    PRINTF_TEST("%d\n", -2147483648);
    PRINTF_TEST("%i\n", 1337);
    PRINTF_TEST("%i\n", 1);
    PRINTF_TEST("%i\n", 0);
    PRINTF_TEST("%i\n", -1);
    PRINTF_TEST("%i\n", 2147483647);
    PRINTF_TEST("%i\n", -2147483648);
    PRINTF_TEST("%u\n", 1);
    PRINTF_TEST("%u\n", 0);
    PRINTF_TEST("%u\n", 324234);
    PRINTF_TEST("%u\n", -1);
    PRINTF_TEST("%o\n", 1);
    PRINTF_TEST("%o\n", 0);
    PRINTF_TEST("%o\n", 324234);
    PRINTF_TEST("%o\n", -1);
    PRINTF_TEST("%x\n", 1);
    PRINTF_TEST("%x\n", 0);
    PRINTF_TEST("%x\n", 324234);
    PRINTF_TEST("%x\n", -1);
    PRINTF_TEST("%X\n", 1);
    PRINTF_TEST("%X\n", 0);
    PRINTF_TEST("%X\n", 324234);
    PRINTF_TEST("%X\n", -1);
    // flag # test
    PRINTF_TEST("%#X\n", 1);
    PRINTF_TEST("%#X\n", 0);
    PRINTF_TEST("%#X\n", 324234);
    PRINTF_TEST("%#X\n", -1);
    PRINTF_TEST("%#x\n", 1);
    PRINTF_TEST("%#x\n", 0);
    PRINTF_TEST("%#x\n", 324234);
    PRINTF_TEST("%#x\n", -1);
    // Flag + test
    PRINTF_TEST("%+d\n", 1337);
    PRINTF_TEST("%+d\n", 1);
    PRINTF_TEST("%+d\n", 0);
    PRINTF_TEST("%+d\n", -1);
    PRINTF_TEST("%+d\n", 2147483647);
    PRINTF_TEST("%+d\n", -2147483648);
    // flag space test
    PRINTF_TEST("% d\n", 1337);
    PRINTF_TEST("% d\n", 1);
    PRINTF_TEST("% d\n", 0);
    PRINTF_TEST("% d\n", -1);
    PRINTF_TEST("% d\n", 2147483647);
    PRINTF_TEST("% d\n", -2147483648);
    PRINTF_TEST("%+u\n", 1);
    PRINTF_TEST("%+u\n", 0);
    PRINTF_TEST("%+u\n", 324234);
    PRINTF_TEST("%+u\n", -1);
    PRINTF_TEST("%+#x\n", 1);
    PRINTF_TEST("%+#x\n", 0);
    PRINTF_TEST("%+#x\n", 324234);
    PRINTF_TEST("%+#x\n", -1);
    PRINTF_TEST("% u\n", 1);
    PRINTF_TEST("% u\n", 0);
    PRINTF_TEST("% u\n", 324234);
    PRINTF_TEST("% u\n", -1);
    PRINTF_TEST("% #x\n", 1);
    PRINTF_TEST("% #x\n", 0);
    PRINTF_TEST("% #x\n", 324234);
    PRINTF_TEST("% #x\n", -1);
    PRINTF_TEST("%p\n", &a);
    PRINTF_TEST("%p\n", &b);
    PRINTF_TEST("%p\n", &c);
    PRINTF_TEST("%s\n", "abc abc abc");
    PRINTF_TEST("%s\n", "");
    PRINTF_TEST("%s\n", "123");
    PRINTF_TEST("%0.20d\n", 1337);
    PRINTF_TEST("%0.2d\n", 1337);
    PRINTF_TEST("%0.1d\n", 1337);
    PRINTF_TEST("%0.100d\n", 1337);

    PRINTF_TEST("%-10d\n", 1337);
    PRINTF_TEST("%10d\n", 1337);
    PRINTF_TEST("%-3d\n", 1337);
    PRINTF_TEST("%-3d\n", 1337);
    PRINTF_TEST("%30.20d\n", 1337);
    PRINTF_TEST("%+-20.10#llx\n", -1);
}

int main()
{
	//char 	*str;
	//char 	c;

	//c = '1';
	//str = strdup("abcde");

	//ft_printf("%-10c.%10c\n", 's', 's');
	//printf("%-10c.%10c\n", 's', 's');
	//int a = ft_printf("%5c  %-1.4s\n", '1', "abcde");
	//int b = printf("%5c  %-1.4s\n", '1', "abcde");

	//int a = ft_printf("%25.15p\n", &c);
	//int b = printf("%25.15p\n", &c);
	//int a = ft_printf("%\n", &c);
	//ft_printf("abcde%c   %s    %10.5d,  %10.2d\n", c, str, 6, 125);
	//printf("abcde%c   %s    %10.5d,  %10.2d\n", c, str, 6, 125);
	//printf("abcde%c   %s\n", c, str);
	//ft_printf("%10.5d\n", 5);
	//printf("%10.5d\n", 5);
	//printf("%lli", 235225227);
	//printf("%lld", 235225227);
	//ft_printf("%p\n", &str);
	//printf("%p\n", &str);

	//printf("%d, %d\n", a, b);
    test();
    return (0);
}
