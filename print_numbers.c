#include "ft_printf.h"

int		print_reverse_int(t_integers data, t_format format, int count)
{
	int 	prec;

	prec = format.precision;
	if (format.flags & FLAG_PLUS)
	{
		count++;
		ft_putchar('+');
	}
	while (prec-- > count_digits(data.ll))
	{
		count++;
		ft_putchar('0');
	}
	count += put_nbr_base(data, 10);
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision, count_digits(data.ll)) + 1)
		{
			ft_putchar(' ');
			format.width--;
			count++;
		}
	}
	return (count);
}

int 	print_modified_int(t_integers data, t_format format)
{
	int 	count;

	count = 0;
	if (format.flags & FLAG_MINUS)
		return (print_reverse_int(data, format, count));
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision, count_digits(data.ll)) + 1)
		{
			ft_putchar(' ');
			format.width--;
			count++;
		}
	}
	if (format.flags & FLAG_PLUS)
	{
		count++;
		ft_putchar('+');
	}
	while (format.precision-- > count_digits(data.ll))
	{
		count++;
		ft_putchar('0');
	}
	return (count + put_nbr_base(data, 10));
}

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
		return put_nbr_base(data, 16);
	if (format.type == 'o')
		return put_nbr_base(data, 8);
	return put_nbr_base(data, 10);
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
	return print_modified_int(data, format);
}