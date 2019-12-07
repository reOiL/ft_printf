#include "ft_printf.h"

int		print_reverse_int(t_integers data, t_format format, int count)
{
	count += print_sign(&data, &format);
	count += put_nbr_base(format, data, 10, 0);
	format.width = (format.flags & FLAG_PLUS) && format.precision == 0 && data.ll == 0 ? format.width + 1 : format.width;
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision, \
					count_digits(data.ll, 10)))
		{
			ft_putchar( ' ');
			format.width--;
			count++;
		}
	}
	return (count);
}

int 	print_modified_int(t_integers data, t_format format)
{
	int		count;
	int		width;
	int 	flag;

	flag = (format.width > count_digits(data.ll, 10) && (format.flags & FLAG_SPACE)) || (format.flags & FLAG_PLUS) || (is_neg(data.ll));
	width = (format.flags & FLAG_PLUS) && format.precision == 0 && data.ll == 0 ? format.width + 1 : format.width;
	count = 0;
	if (format.flags & FLAG_MINUS)
		return (print_reverse_int(data, format, count));
	count += ((format.flags & FLAG_ZERO) && (format.width < format.precision || format.precision < 0)) ? print_sign(&data, &format) : 0;
	if (width > format.precision)
	{
		while (width - flag > ft_max(format.precision, count_digits(data.ll, 10) - is_neg(data.ll)))
		{
			ft_putchar((format.flags & FLAG_ZERO) && format.precision < 0 ? '0' : ' ');
			width--;
			count++;
		}
	}
	count += !((format.flags & FLAG_PLUS || format.flags & FLAG_SPACE) && (format.flags & FLAG_ZERO)) || (format.width >= format.precision && format.precision > -1) ? print_sign(&data, &format) : 0;
	return (count + put_nbr_base(format, data, 10, 0));
}

int		print_int(t_format format, va_list args)
{
	t_integers  data;

	if (format.modifier & MOD_H)
		data.ll = (short)va_arg(args, int);
	else if (format.modifier & MOD_HH)
		data.ll = (signed char)va_arg(args, int);
	else if (format.modifier & MOD_L)
		data.ll = (long)va_arg(args, long);
	else if (format.modifier & MOD_LL)
		data.ll = (long long)va_arg(args, long long);
	else
		data.ll = (int)va_arg(args, int);
	return (print_modified_int(data, format));
}