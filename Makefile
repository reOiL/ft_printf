# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 17:06:25 by jwebber           #+#    #+#              #
#    Updated: 2019/11/14 10:39:23 by jwebber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_itoa_base.c \
        ft_itoa_base_uns.c \
        ft_printf.c \
        get_format.c \
        helper_numbers.c \
        print_addr_helper.c \
        print_chars_helper.c \
        print_float.c \
        print_ints_helper.c \
        print_uns_helper.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_PATH = libft/

LIBFT = libft.a

.c.o:
	@gcc $(FLAGS) -c $< -o $@
	@printf "\e[32m😲 😲 😲  build success \e[36m$<\n"

$(NAME): $(OBJ) $(LIBFT_PATH)$(LIBFT)
	@ar rc $(NAME) $(OBJ) $(LIBFT_PATH)$(LIBFT)
	@printf "\e[36m 🏁  👍  👍  👍  $(NAME) 👍  👍  👍  🏁  !\n"

$(LIBFT_PATH)$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)
	@printf "\e[33mCleaned 😵 😵 😵 😵  !!!\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
	@printf "\e[31mFull cleaned 💀 💀 💀 💀  !!!\n"

re: fclean all
