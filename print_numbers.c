#include "ft_printf.h"

int		print_int(t_format format, va_list args)
{

	if (format.modifier == 0)
		return (print_normal_int(format, va_arg(args, int)));
	if (format.modifier == 1)
		return (print_long_int(format, va_arg(args, long int)));
	else if (format.modifier == 2)
	 	return (print_short_int(format, va_arg(args, short int)));
	else if (format.modifier == 3)
		return (print_long_long_int(format, va_arg(args, long long int)));
	else if (format.modifier == 4)
		return (print_signed_char_int(format, va_arg(args, char)));


	/*
	if (format.width > format.precision)
	{
		while (format.width > format.precision && format.width > count_digits(value))
		{
			ft_putchar(' ');
			format.width--;
		}
	}
	while (format.precision-- > count_digits(value))
		ft_putchar('0');
	ft_putnbr(value);
	 */
}