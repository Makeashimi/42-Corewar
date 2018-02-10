/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:57:38 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/09 21:58:33 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <inttypes.h>
# include <stdint.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../../op.h"
# include "../../libft/libft.h"

typedef struct				s_instruction
{
	char					*label;
	char					*name;
	char					index;
	char					*param1;
	char					*param2;
	char					*param3;
	char					type[3];
	struct s_instruction	*next;
}							t_instruction;

typedef struct				s_asm
{
	char					*str;
	struct s_asm			*next;
}							t_asm;

int							ft_space(char c);
int							is_all_space(char *str);
t_asm						*begin_parse(t_asm *l_asm);
void						parse_instructions(t_instruction
												*instruction, t_asm *tmp);
int							is_label(t_instruction *instruction, char *str);
int							is_name_instru(t_instruction *instruction,
																	char *str);
t_instruction				*link_instruction(t_instruction **instruction);
int							check_param(t_instruction *instruction, char *tmp);
t_instruction				*get_last_instru(t_instruction *instruction);
void						check_reg(char *str, int i, t_instruction *ins);
void						check_dir(char *str, int i, t_instruction *ins);
void						error(char *str);

#endif
