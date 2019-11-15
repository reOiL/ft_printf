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

# define FLAG_ZERO 0x2
# define FLAG_SHARP 0x4
# define FLAG_PLUS 0x8
# define FLAG_MINUS 0x10
# define FLAG_SPACE 0x20

# define MOD_L 0x2
# define MOD_LL 0x4
# define MOD_H 0x8
# define MOD_HH 0x10

/* Спецификаторы:
 * c +
 * s +
 * p +
 * d +
 * i +
 * o +
 * x +
 * X +
 * f -
 */

typedef union   		u_integers
{
	long long           ll;
	unsigned long long  ull;
}               		t_integers;

typedef struct			s_format
{
	unsigned int		flags;		// 5 флагов (0,#,+,-, ), значение каждого элемента массива - 0 или 1.
									// При нахождении флага после % соответсвующее значение установится в 1
									// (Но некоторые флаги несовместимы, с этим надо подумать.)
	int					width;		// Ширина поля
	int					precision;	// Точность.
	int					modifier;	// Модификаторы (l, h, ll, hh, L)(пока хз как лучше это сделать), возвращаемое значение указывает на модификатор, без = 0, l = 1, h = 2, ll = 3, hh = 4, L = 5
	char				type;		// Тип преобразования.(или int)
}						t_format;

/*
 * Примерно план такой - двигаем указатель по данной строке и печатаем символы, при встрече 
 * % передаем указатель в функцию, которая будет возвращать инт - сдвиг указателя после 
 * печати сооветсвующего значения. (i += print_value(str[i], ...)). При невалидных значениях 
 * после % функция будет возвращать 0, что будет означать печать тех символов, что есть в 
 * строке
*/

//print_percent_helper.c
int 					print_percent(t_format format);

//print_char_helper.c
int						print_char(t_format format, va_list args);
int						print_string(t_format format, va_list args);

//print_addr_helper.c
long long				ft_max(long long a, long long b);
char 					*get_addr_precision(char *num, int precision);
int 					ft_putstr_size(char *str, int precision);
int 					print_address(t_format format, va_list args);

//ft_itoa_base.c
int						calc_len(long long val, int base);
char					cast_base(unsigned short val);
void					itoa_2(char **array, long long val, int base, long long index);
char					*ft_itoa_base(long long ll, int base);

//ft_itoa_base_uns.c
int						calc_len_uns(unsigned long long val, int base);
void					itoa_2_uns(char **array, unsigned long long val, int base, long long index);
char					*ft_itoa_base_uns(unsigned long long ull, int base);

//helper_numbers.c
int 					is_neg(long long val);
int 					print_sign(t_integers *data, t_format format);
int						count_digits(long long value, int base);
int						count_digits_uns(unsigned long long value, int base);
int             		put_nbr_base(t_format format, t_integers val, int base, int uns_sign);

//print_uns_helper.c
int 					print_x(t_format format);
char					*ft_tolower_str(char *str);
int 					print_reverse_uns(t_integers data, t_format format, int count, int base);
int 					print_modified_uns(t_integers data, t_format format, int base);
int						print_int_unsigned(t_format format, va_list args);

//print_ints_helper.c
int						print_reverse_int(t_integers data, t_format format, int count);
int 					print_modified_int(t_integers data, t_format format);
int						print_int(t_format format, va_list args);

//get_format.c
unsigned int 			get_flags(const char *str, int *it);
int 					get_width(const char *str, int *i);
int 					get_precision(const char *str, int *i);
int						get_modifier(const char *str, int *i);
char 					get_type(const char *str);

//ft_printf.c
int						print_value(t_format format, va_list args);
int						get_format(va_list args, const char *str, int *printed_count);
int						ft_printf(const char *format, ...);

//Не реализованы
int						print_float(t_format format, va_list args);

#endif //FT_PRINTF_H
