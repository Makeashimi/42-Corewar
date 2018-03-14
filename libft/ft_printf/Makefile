# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 14:04:45 by jcharloi          #+#    #+#              #
#    Updated: 2018/01/09 13:34:21 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
	check_after.c \
	check_param.c \
	print_flags.c \
	print_width.c \
	print_precision.c \
	print_params.c \
	print_c.c \
	print_s.c \
	print_di.c \
	print_ou.c \
	print_p.c \
	print_x.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ)
	@libtool -static -o $@ $^ ../libft.a

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: clean fclean all

.PHONY: clean fclean re
