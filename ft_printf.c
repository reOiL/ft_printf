/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:42:23 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 16:42:24 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	szTotalLen;
	char 	*tmp;
	va_list	ap;

	szTotalLen = ft_strlen(format);
	va_start(ap, format);
	tmp = NULL;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			continue;
		}
		format++;
		if (*format == 'd' || *format == 'i')
			tmp = ft_itoa_base(va_arg(ap, int), 10);
		else if (*format == 'x' || *format == 'X')
			tmp = ft_itoa_base(va_arg(ap, int), 16);
		else if (*format == 's')
			tmp = va_arg(ap, char*);
		if (tmp)
		{
			szTotalLen += ft_strlen(tmp);
			ft_putstr(tmp);
			if (*format != 's')
				ft_memdel((void**)&tmp);
		}
		format++;
	}
	va_end(ap);
	return (0);
}