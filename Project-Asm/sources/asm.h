/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:57:38 by jcharloi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/02/14 15:16:53 by varichar         ###   ########.fr       */
=======
/*   Updated: 2018/01/23 11:49:39 by jcharloi         ###   ########.fr       */
>>>>>>> 27d211396ddca237701973d9ebfdb5907ab1f87c
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
# include <fcntl.h>

typedef struct				s_instruction
{
	char					*label;
	char					*name;
	char					index;
	int						size;
	int						address;
	char					*param[3];
	char					type[3];
	struct s_instruction	*next;
}							t_instruction;

<<<<<<< HEAD
typedef struct				s_asm
{
	char					*str;
	char					*champname;
	char					*comment;
	struct s_asm			*next;
}							t_asm;

int							ft_space(char c);
int							is_all_space(char *str);
t_asm						*begin_parse(t_asm *l_asm);
void						check_next_content(t_asm *l_asm, char *str,
														char *message, char c);
t_asm						*parse_instructions(t_instruction
												*instruction, t_asm *tmp);
int							is_label(t_instruction *instruction, char *str);
int							is_name_instru(t_instruction *instruction,
																	char *str);
t_instruction				*link_instruction(t_instruction **instruction);
int							check_param(t_instruction *instruction, char *tmp);
t_instruction				*get_last_instru(t_instruction *instruction);
int							check_reg(t_instruction *instruction, char *str,
																		int i);
int							check_dir(t_instruction *instruction, char *str,
																		int i);
int							check_ind(t_instruction *instruction, char *str,
																		int i);
void						error(char *str);
int							rev_end(int val, char size);

void						wr_header(int fd, t_asm *l_asm, t_instruction *ins);
void						wr_ins(int fd, t_instruction *ins);
void						assign_size_ins(t_instruction *ins);
int							get_byte_nb(t_instruction *ins, int i);


/* DEBUG */
t_instruction				*debug_ins(void);
=======
void				parse_name(t_asm *l_asm);
void				error(char *str);
>>>>>>> 27d211396ddca237701973d9ebfdb5907ab1f87c

#endif
