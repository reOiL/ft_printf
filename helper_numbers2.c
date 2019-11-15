#include "ft_printf.h"

int 		check_zero_number(t_format format, t_integers val)
{
	if (!format.precision && val.ull == 0 && (format.type == 'x' \
	|| format.type == 'X' || (format.type == 'o' && !(format.flags & FLAG_SHARP))))
		return (1);
	if (!format.precision && val.ll == 0 && (format.type == 'd' || format.type == 'i'))
		return (1);
	return (0);
}
