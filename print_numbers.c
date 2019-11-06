#include "ft_printf.h"

void	print_int(t_format format, int value)
{
	int 	max;

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
}