#include "ft_printf.h"

int		print_int_unsigned(t_format format, va_list args)
{
    t_integers  data;

    if (format.modifier & MOD_H)
        data.ull = (unsigned short)va_arg(args, int);
    else if (format.modifier & MOD_HH)
        data.ull = (unsigned char)va_arg(args, int);
    else if (format.modifier & MOD_L)
        data.ull = (unsigned long)va_arg(args, unsigned long);
    else if (format.modifier & MOD_LL)
        data.ull = (unsigned long long)va_arg(args, unsigned long long);
    else
        data.ull = (unsigned int)va_arg(args, unsigned int);

    if (format.type == 'x' || format.type == 'X')
        return put_nbr_base(data, format, 16);
    if (format.type == 'o')
        return put_nbr_base(data, format, 8);
    return put_nbr_base(data, format, 10);
}

int		print_int(t_format format, va_list args)
{
    t_integers  data;

    if (format.modifier & MOD_H)
        data.ll = (short)va_arg(args, int);
    else if (format.modifier & MOD_HH)
        data.ll = (signed char)va_arg(args, int);
    else if (format.modifier & MOD_L)
        data.ll = (long int)va_arg(args, long int);
    else if (format.modifier & MOD_LL)
        data.ll = (long long)va_arg(args, long long int);
    else
        data.ll = (int)va_arg(args, int);
    return put_nbr_base(data, format, 10);
}