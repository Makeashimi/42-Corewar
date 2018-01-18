# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 11:44:59 by jcharloi          #+#    #+#              #
#    Updated: 2018/01/18 17:38:26 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = GCC
CFLAGS = -Wall -Wextra -Werror -MMD
NAME1 = asm
NAME2 = corewar

ASM_SRC_PATH = ./Project-Asm/sources/
ASM_SRC_NAME = main.c
ASM_OBJ_PATH = ./Project-Asm/objects/
ASM_OBJ_NAME = $(ASM_SRC_NAME:.c=.o)

COR_SRC_PATH = ./Project-Corewar/sources/
COR_SRC_NAME = main.c
COR_OBJ_PATH = ./Project-Corewar/objects/
COR_OBJ_NAME = $(COR_SRC_NAME:.c=.o)

LIB_PATH = ./libft/
LIB_NAME = ./libft/libft.a
PRINT_NAME = ./libft/ft_printf/libftprintf.a

ASM_OBJ = $(addprefix $(ASM_OBJ_PATH),$(ASM_OBJ_NAME))
COR_OBJ = $(addprefix $(COR_OBJ_PATH),$(COR_OBJ_NAME))

YELLOW = "\033[3;38;5;228m"
ORANGE = "\033[3;38;5;214m"
RED = "\033[3;49;31m"
PINK = "\033[3;38;5;205m"
PURPLE = "\033[3;38;5;98m"
BLUE = "\033[3;38;5;39m"
GREEN = "\033[3;33;32m"
EOC = "\033[0m"

all: creation
	@make $(NAME1)
	@make $(NAME2)

$(NAME1): $(ASM_OBJ)
	@$(CC) -o $(NAME1) $(ASM_OBJ) $(LIB_NAME) $(PRINT_NAME) $(CFLAGS)
	@echo $(GREEN)"Your $(NAME1) is ready to work ! ✅"$(EOC)

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $(BLUE)"Your $(ASM_OBJ) is ready to work !"$(EOC)

$(NAME2): $(COR_OBJ)
	@$(CC) -o $(NAME2) $(COR_OBJ) $(LIB_NAME) $(PRINT_NAME) $(CFLAGS)
	@echo $(GREEN)"Your $(NAME2) is ready to work ! ✅"$(EOC)

$(COR_OBJ_PATH)%.o: $(COR_SRC_PATH)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $(BLUE)"Your $(COR_OBJ) is ready to work !"$(EOC)

creation:
	@make -C $(LIB_PATH)
	@echo $(ORANGE)"Your $(LIB_NAME) and your $(PRINT_NAME) are (al)ready (ready) to work !"$(EOC)
	@mkdir $(ASM_OBJ_PATH) 2> /dev/null || true
	@echo $(RED)"Your $(ASM_OBJ_PATH) is (al)ready (ready) to work !"$(EOC)
	@mkdir $(COR_OBJ_PATH) 2> /dev/null || true
	@echo $(RED)"Your $(COR_OBJ_PATH) is (al)ready (ready) to work !"$(EOC)

-include $(ASM_OBJ:.o=.d)
-include $(COR_OBJ:.o=.d)

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(ASM_OBJ_PATH)
	@rm -rf $(COR_OBJ_PATH)
	@echo $(PURPLE)"Make clean done !"$(EOC)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@echo $(PINK)"Make fclean done !"$(EOC)

re: fclean all

.PHONY : all creation clean fclean re