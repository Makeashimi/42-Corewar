# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 11:44:59 by jcharloi          #+#    #+#              #
#    Updated: 2018/03/09 15:11:52 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = GCC
DEBUGFLAGS = -ggdb
CFLAGS = -Wall -Wextra -Werror -MMD
NAME1 = asm
NAME2 = corewar

ASM_SRC_PATH = ./project_asm/sources/
ASM_SRC_NAME =	endian.c\
				instructions.c\
				main.c\
				param.c\
				registre_name_comment.c\
				parsing_parameters.c\
				parsing_instructions.c\
				parsing_comment.c\
				parsing_name.c\
				tools.c\
				label.c \
				write.c\
				size.c
ASM_OBJ_PATH = ./project_asm/objects/
ASM_OBJ_NAME = $(ASM_SRC_NAME:.c=.o)

VM_SRC_PATH = ./project_vm/sources/
VM_SRC_NAME = main.c \
			take_arg.c \
			calc_ocp.c \
			parse_champ.c \
			init_data.c \
			check.c \
			check2.c \
			list_proc.c \
			ft_battle.c \
			ft_add.c \
			ft_aff.c \
			ft_and.c \
			ft_fork.c \
			ft_jump.c \
			ft_ld.c \
			ft_lfork.c \
			ft_live.c \
			ft_lld.c \
			ft_lldi.c \
			ft_or.c \
			ft_st.c \
			ft_sti.c \
			ft_sub.c \
			ft_xor.c \
			ft_ldi.c \
			print_memory.c
VM_OBJ_PATH = ./project_vm/objects/
VM_OBJ_NAME = $(VM_SRC_NAME:.c=.o)

LIB_PATH = ./libft/
LIB_NAME = ./libft/libft.a
PRINT_NAME = ./libft/ft_printf/libftprintf.a

ASM_OBJ = $(addprefix $(ASM_OBJ_PATH),$(ASM_OBJ_NAME))
VM_OBJ = $(addprefix $(VM_OBJ_PATH),$(VM_OBJ_NAME))

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

$(NAME1): $(ASM_OBJ) op.o
	@$(CC) -o $(NAME1) $(ASM_OBJ) op.o $(LIB_NAME) $(PRINT_NAME) $(CFLAGS)
	@echo $(GREEN)"Your ./$(NAME1) is ready to work ! ✅"$(EOC)

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $(BLUE)"Your $@ is compiled !"$(EOC)

$(NAME2): $(VM_OBJ) op.o
	@$(CC) -o $(NAME2) $(VM_OBJ) op.o $(LIB_NAME) $(PRINT_NAME) $(CFLAGS)
	@echo $(GREEN)"Your ./$(NAME2) is ready to work ! ✅"$(EOC)

$(VM_OBJ_PATH)%.o: $(VM_SRC_PATH)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $(BLUE)"Your $@ is compiled !"$(EOC)

op.o: op.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $(BLUE)"Your $@ is compiled !"$(EOC)

creation:
	@make -C $(LIB_PATH)
	@echo $(ORANGE)"Your $(LIB_NAME) and your $(PRINT_NAME) are (al)ready (ready) to work !"$(EOC)
	@mkdir $(ASM_OBJ_PATH) 2> /dev/null || true
	@echo $(RED)"Your $(ASM_OBJ_PATH) is (al)ready (ready) to work !"$(EOC)
	@mkdir $(VM_OBJ_PATH) 2> /dev/null || true
	@echo $(RED)"Your $(VM_OBJ_PATH) is (al)ready (ready) to work !"$(EOC)

-include $(ASM_OBJ:.o=.d)
-include $(VM_OBJ:.o=.d)
-include op.o=.d

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(ASM_OBJ_PATH)
	@rm -rf $(VM_OBJ_PATH)
	@rm -f op.o
	@rm -f op.d
	@echo $(PURPLE)"Make clean done !"$(EOC)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@echo $(PINK)"Make fclean done !"$(EOC)

re: fclean all

.PHONY : all creation clean fclean re
