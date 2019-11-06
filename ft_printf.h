/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:42:23 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 16:42:24 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/* Спецификаторы:
 * c
 * s
 * p
 * d
 * i
 * o
 * x
 * X
 * f
 */
typedef struct	s_format
{
	int			flags[5];	// 5 флагов (0,#,+,-, ), значение каждого элемента массива - 0 или 1. 
							// При нахождении флага после % соответсвующее значение установится в 1
							// (Но некоторые флаги несовместимы, с этим надо подумать.)
	int			width;		// Ширина поля
	int			precision;	// Точность.
	int			modifier;	// Модификаторы (l, h, ll, hh, L)(пока хз как лучше это сделать), возвращаемое значение указывает на модификатор, без = 0, l = 1, h = 2, ll = 3, hh = 4, L = 5
	char		type;		// Тип преобразования.(или int)
	//void		*value;		// Нужен ли нам в этой структуре указатель на выводимое значение?
}				t_format;

/*
 * Примерно план такой - двигаем указатель по данной строке и печатаем символы, при встрече 
 * % передаем указатель в функцию, которая будет возвращать инт - сдвиг указателя после 
 * печати сооветсвующего значения. (i += print_value(str[i], ...)). При невалидных значениях 
 * после % функция будет возвращать 0, что будет означать печать тех символов, что есть в 
 * строке
*/

//helper_numbers.c
int				count_digits(long long int value);

//print_numbers.c
int				print_int(t_format format, va_list args);

//print_ints_helper.c
int				print_normal_int(t_format format, int value);		//format.modifier = 0
int				print_long_int(t_format format, long int value);			//format.modifier = 1 (l)
int				print_short_int(t_format format, int value);		//format.modifier = 2 (h)
int				print_long_long_int(t_format format, long long int value);	//format.modifier = 3 (ll)
int				print_signed_char_int(t_format format, int value);	//format.modifier = 4 (hh)

//get_format.c
int 			get_width(const char *str, int *i);
int 			get_precision(const char *str, int *i);
int				get_modifier(const char *str, int *i);
char 			get_type(const char *str);


//ft_printf.c
int				print_value(t_format format, va_list args);
int				get_format(va_list args, const char *str, int *printed_count);
int				ft_printf(const char *format, ...);

//Не реализованы
int				print_char(t_format format, va_list args);
int				print_string(t_format format, va_list args);
int				print_address(t_format format, va_list args);
int				print_oct(t_format format, va_list args);
int				print_unsigned(t_format format, va_list args);
int				print_low_hex(t_format format, va_list args);
int				print_high_hex(t_format format, va_list args);
int				print_float(t_format format, va_list args);

#endif //FT_PRINTF_H
