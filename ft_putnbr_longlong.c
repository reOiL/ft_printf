#include "ft_printf.h"

//Count будет возвращать количество напечатанных символов
int		ft_putnbr_long_long(long long int n, int count)
{
	long long	ll;

	ll = n;
	if (ll == 0) {
		ft_putchar('0');
		return (count + 1);
	}
	if (ll < 0) {
		ft_putchar('-');
		ll *= -1;
		count++;
	}
	if (ll / 10 != 0)
		return (ft_putnbr_long_long(ll / 10, count + 1));
	ft_putchar('0' + ll % 10);
	return (count + 1);
}

int		ft_putnbr_unsigned(long long unsigned int n, int count)
{
	if (n == 0)
	{
		ft_putchar('0');
		return (count + 1);
	}
	if (n / 10 != 0)
		ft_putnbr_unsigned(n / 10, count + 1);
	ft_putchar('0' + n % 10);
	return (count + 1);
}

//16ричная - проблема с выводом отрицательных чисел. В 8ричной скорее всего будет тоже
/*
int 	ft_putnbr_hex(long long int n, int upcase, int count)
{
	if (n == 0) {
		ft_putchar('0');
		return (count + 1);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n / 16 != 0)
		ft_putnbr_long_long(n / 16);
	if (n % 16 < 10)
		ft_putchar('0' + n % 16);
	else
		ft_putchar('a' + n % 16 + upcase);
}
*/