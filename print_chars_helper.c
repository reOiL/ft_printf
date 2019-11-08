#include "ft_printf.h"

int			print_char(t_format format, va_list args)
{
	int 	width;

	width = format.width;
	if (format.flags & FLAG_MINUS)
	{
		ft_putchar((char)va_arg(args, int));
		while (width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (width-- > 1)
			ft_putchar(' ');
		ft_putchar((char)va_arg(args, int));
	}
	return (1 + format.width);
}

//TODO atoi_base16 добавить (и формат x X) Аналогично с сhar, применяется только флаг '-'
int 		print_address(t_format format, va_list args)
{
	long long unsigned n;

	/*
	ft_putstr("0x");
	n = va_arg(args, long long unsigned);
	if (n / 16 != 0)
		ft_putnbr_long_long(n / 10, 0);
	ft_putchar('0' + n % 10);
	 */
}