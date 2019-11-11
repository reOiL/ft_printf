#include "ft_printf.h"

int 	print_uns(t_integers data, t_format format, int base)
{
	int 	count;

	count = 0;
//	if (format.flags & FLAG_MINUS)
//		return (print_reverse_uns(data, format, count));
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision, count_digits_uns(data.ull, base)) + 1)
		{
			ft_putchar(' ');
			format.width--;
			count++;
		}
	}
	if (format.flags & FLAG_PLUS)
		count += print_sign(&data, format);
	while (format.precision-- > count_digits_uns(data.ull, base))
	{
		count++;
		ft_putchar('0');
	}
	return (count + put_nbr_base(data, base, 1));
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
		return print_uns(data, format, 16);
	if (format.type == 'o')
		return print_uns(data, format, 8);
	return print_uns(data, format, 10);
}