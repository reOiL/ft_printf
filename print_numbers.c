#include "ft_printf.h"

int		print_int(t_format format, va_list args)
{
	if (format.modifier == 1)
		return (print_long_int(format, va_arg(args, long int)));
	else if (format.modifier == 2)
	 	return (print_short_int(format, va_arg(args, int)));
	else if (format.modifier == 3)
		return (print_long_long_int(format, va_arg(args, long long int)));
	else if (format.modifier == 4)
		return (print_signed_char_int(format, va_arg(args, int)));
	else
		return (print_normal_int(format, va_arg(args, int)));
}