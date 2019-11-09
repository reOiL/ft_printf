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
# include "floating.h"

# define FLAG_ZERO 0x2
# define FLAG_SHARP 0x4
# define FLAG_PLUS 0x8
# define FLAG_MINUS 0x10
# define FLAG_SPACE 0x20

# define MOD_L 0x2
# define MOD_LL 0x4
# define MOD_H 0x8
# define MOD_HH 0x10

typedef struct	s_format
{
    // Битывые операции, тип данных лучше взять меньше, например short
    // Пример: если стоит флаг 0 и флаг -, то в битовом виде мы получим:
    // 100010 это получается за счёт логического или (0x2 | 0x20 = 0x22)
    // Чтобы проверить есть ли этот флаг, надо просто выполнить операцию и (0x22|0x20 = 0x20)
    unsigned int flags;  	// 5 флагов (0,#,+,-, ), значение каждого элемента массива - 0 или 1.
							// При нахождении флага после % соответсвующее значение установится в 1
							// (Но некоторые флаги несовместимы, с этим надо подумать.)
	int			width;		// Ширина поля
	int			precision;	// Точность. Мб при отсутсвии значений точности и ширины, можно их инициализировать как -1?
	// Тоже самое что и с флагами
    unsigned int modifier;   // Модификаторы (l, h, ll, hh)(или все таки char[2]?)
	char		type;		// Тип преобразования.(или int)
	void		*value;		// Нужен ли нам в этой структуре указатель на выводимое значение?
}				t_format;

/*
 * Примерно план такой - двигаем указатель по данной строке и печатаем символы, при встрече 
 * % передаем указатель в функцию, которая будет возвращать инт - сдвиг указателя после 
 * печати сооветсвующего значения. (i += print_value(str[i], ...)). При невалидных значениях 
 * после % функция будет возвращать 0, что будет означать печать тех символов, что есть в 
 * строке
*/

typedef union   u_floating{
    float       f;
    int         i;
    double      f64;
    long long   i64;
}               t_ufloating;

typedef union   u_integers
{
    long long           ll;
    unsigned long long  ull;
}               t_integers;

char 			get_type(const char *str);

int				ft_printf(const char *format, ...);

unsigned int    get_flags(const char *str, int *it);

unsigned int    get_modifier(const char *str, int *it);

int				print_float(t_format format, va_list args);

t_floating      parse_float(float val);

int             put_nbr_base(t_integers val, t_format format, int base);
#endif //FILLIT_FT_PRINTF_H
