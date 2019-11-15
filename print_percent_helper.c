#include "ft_printf.h"

int 	print_percent(t_format format)
{
	int 	count;

	count = 0;
	if (format.flags & FLAG_MINUS)
	{
		ft_putchar('%');
		count++;
		while (count < format.width)
		{
			ft_putchar(' ');
			count++;
		}
		return (count);
	}
	else
	{
		while (format.width-- > 1)
		{
			count++;
			ft_putchar(' ');
		}
		ft_putchar('%');
		return (count + 1);
	}
}