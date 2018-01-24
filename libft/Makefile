# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 16:15:21 by jcharloi          #+#    #+#              #
#    Updated: 2018/01/09 13:34:14 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRC = 	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_ato.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_iswhitespace.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strdel.c \
		ft_strnew.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_sqrt.c \
		ft_tabdel.c \
		ft_strsrchi.c \
		get_next_line.c \
		ft_len.c \
		ft_signedbase.c \
		ft_unsignedbase.c \
		ft_print_wchart.c \
		ft_abs.c \
		tab.c \
		ft_error.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)
	@make -C ft_printf/

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@make clean -C ft_printf/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ft_printf/

re: fclean all

.PHONY: all clean fclean re
