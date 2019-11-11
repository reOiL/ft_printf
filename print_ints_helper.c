#include "ft_printf.h"

//TODO Решить проблему с флагами + и -
int		print_reverse_int(t_integers data, t_format format, int count)
{
	int 	sign;
	int 	prec;

	sign = is_neg(data.ll) || (format.flags & FLAG_PLUS);
	prec = format.precision;
	//if (format.flags & FLAG_PLUS || is_neg(data.ll))
		count += print_sign(&data, format);
	while (prec-- > count_digits(data.ll, 10))
	{
		count++;
		ft_putchar('0');
	}
	count += put_nbr_base(data, 10, 0);
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision, count_digits(data.ll, 10)) + sign)
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
	int 	sign;

	count = 0;
	sign = (is_neg(data.ll) || (format.flags & FLAG_PLUS));
	if (format.flags & FLAG_MINUS)
		return (print_reverse_int(data, format, count));
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision + sign, count_digits(data.ll, 10) + ((format.flags & FLAG_PLUS || format.flags & FLAG_SPACE) && data.ll > 0)))
		{
			ft_putchar(format.flags & FLAG_ZERO ? '0' : ' ');
			format.width--;
			count++;
		}
	}
	//if (format.flags & FLAG_PLUS || is_neg(data.ll))
		count += print_sign(&data, format);
	while (format.precision-- > count_digits(data.ll, 10))
	{
		count++;
		ft_putchar('0');
	}
	return (count + put_nbr_base(data, 10, 0));
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
	return (print_modified_int(data, format));
}