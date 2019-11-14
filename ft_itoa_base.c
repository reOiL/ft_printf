#include "ft_printf.h"

int		calc_len(long long val, int base)
{
	if (val == 0)
		return (1);
	return calc_len(val / base, base) + 1;
}

char	cast_base(unsigned short val)
{
	char 		c;

	c = '0';
	if (val >= 0 && val <= 9)
		c += val;
	else if (val >= 10 && val <= 16)
		c = (val - 10) + 'A';
	return (c);
}

void	itoa_2(char **array, long long val, int base, long long index)
{
	if (val / base != 0)
		itoa_2(array, val / base, base, index - 1);
	(*array)[index] = cast_base(val % base);
}

char	*ft_itoa_base(long long ll, int base)
{
	char 		*array;
	long long 	len;
	int 		is_minus;

	if (base < 2 || base > 16)
	{
		array = ft_strnew(1);
		array[0] = '0';
		return (array);
	}
	is_minus = 0;
	if (ll < 0)
	{
		if (base == 10)
			is_minus = 1;
		ll *= -1;
	}
	len = calc_len(ll, base) + (ll == 0);
	array = ft_strnew((len + is_minus));
	if (is_minus)
		array[0] = '-';
	itoa_2(&array, ll, base, len - (2 - is_minus));
	array[len - (1 - is_minus)] = '\0';
	return (array);
}