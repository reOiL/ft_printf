//
// Created by reoil on 07.11.2019.
//

#include "ft_printf.h"
#include <stdio.h>

t_floating      parse_float(float val)
{
    t_floating  ret;
    t_ufloating f;

    ft_memset(&f, 0, sizeof(f));
    ft_memset(&ret, 0, sizeof(ret));
    f.f = val;
    ret.sign = (f.i >> 31) ? -1 : 1;
    ret.order = (f.i >> 23) & 0xFF;
    ret.mantisa = ret.order ? (f.i & 0x7FFFFF) | 0x800000 : (f.i & 0x7FFFFF) << 1;
    int a = (ret.order - 127);
    int b = a > 0 ? ((ret.mantisa << a) & 0x7FFFFF) : ret.mantisa;
    return (ret);
}

int				print_float(t_format format, va_list args)
{
    double d = va_arg(args, double);
    int i = 0;
    long long g = (long long)d;
    //todo: число меньше нуля
    printf("%lli.", g); // todo: replace with ft_putnbr
    //d -= (double))_d;
    //todo: округлить число
    while (i < 6) // todo: while i < precision
    {
        d *= 10;
        printf("%c",(char)('0' + (int)(d) % 10));
        i++;
        d -= (double)(long long)d;
    }
    return (0);
}