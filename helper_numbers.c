#include "ft_printf.h"

//TODO Возможно нужен еще подсчет для 16 и 8
int 	count_digits(long long int value)
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