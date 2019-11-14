//
// Created by reoil on 07.11.2019.
//

#include "ft_printf.h"
#include <stdio.h>

int				print_float(t_format format, va_list args)
{
	double d;
    int i;
	t_integers  data;
	t_format format1;
	double acur;

	d  = va_arg(args, double);
    data.ll = (long long)d;
    i = 0;
    acur = 5;
    ft_memset(&format1, 0, sizeof(format1));
    format1.modifier = MOD_LL;
    format.precision = format.precision < 0 ? 6 : format.precision;
	data.ll += print_modified_int(data, format1);
    //todo: число меньше нуля
    if(format.precision == 0)
		return ((int)data.ll);
    ft_putchar('.');
	while (i < format.precision + 1)
	{
		acur /= 10;
		i++;
		data.ll++;
	}
	d += acur;
    while (--i > 0 )
    {
        d *= 10;
        ft_putchar((char)('0' + (unsigned long long)(d) % 10));
        //d -= (double)(long long)d;
    }
    return ((int)data.ll);
}