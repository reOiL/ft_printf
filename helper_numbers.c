#include "ft_printf.h"

int 	count_digits(int value)
{
	int		i;

	i = 1;
	while (value / 10)
	{
		i++;
		value /= 10;
	}
	return (i);
}