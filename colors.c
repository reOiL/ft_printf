//
// Created by Johnny Webber on 16/11/2019.
//

#include "color.h"
#include "libft/libft.h"

char	*code_to_color(char *code)
{
	if (ft_strncmp(code, "{red}", 5))
		return "\e[31m";
	if (ft_strncmp(code, "{green}", 7))
		return "\e[32m";
	if (ft_strncmp(code, "{blue}", 6))
		return "\e[34m";
	return "";
}