//
// Created by reoil on 07.11.2019.
//

#include "ft_printf.h"

int				print_float(t_format format, va_list args)
{
    double d = va_arg(args, double);
    long long g = (long long)d;
    return (0);
}