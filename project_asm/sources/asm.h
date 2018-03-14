/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:57:38 by jcharloi          #+#    #+#             */
/*   Updated: 2018/03/09 15:05:06 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "../../op.h"
# include "../../libft/libft.h"

# define FILE_RIGHTS 0600

typedef struct				s_instruction
{
	char					**label;
	char					*name;
	char					index;
	int						size;
	int						address;
	char					*param[3];
	char					type[3];
	struct s_instruction	*next;
}							t_instruction;

typedef struct				s_asm
{
	char					*str;
	char					**champname;
	char					**comment;
	int						len;
	struct s_asm			*next;
}							t_asm;

int							ft_space(char c);
int							is_all_space(char *str);
t_asm						*begin_parse(t_asm *l_asm);
int							get_last_line(t_asm *l_asm, t_asm **tmp, int *count,
																	char *mes);
void						check_characters_after(char *str, char *message);
void						next_tmp(t_asm **tmp, char *mes);
void						get_name(t_asm *l_asm, t_asm *tmp, int count,
																		int i);
void						get_comment(t_asm *l_asm, t_asm *tmp, int count,
																		int i);
int							count_content(t_asm *l_asm, char *str);
void						registerr(t_asm *l_asm, t_asm *tmp, char **str,
																		int i);
void						check_next_content(t_asm *l_asm, char *str,
														char *message, char c);
void						check_len(t_asm *l_asm, char c);
t_asm						*parse_instructions(t_instruction *instruction,
													t_asm *tmp, int i);
int							is_label(t_instruction *instruction, char *str,
																int o, int ret);
int							is_confurm_label(char c);
char						*instru(char *str);
int							is_name_instru(t_instruction *instruction,
																	char *str);
t_instruction				*link_instruction(t_instruction **instruction);
char						*move_to_param(char *str);
int							check_param(t_instruction *instruction, char *tmp);
t_instruction				*get_last_instru(t_instruction *instruction);
int							check_reg(t_instruction *instruction, char *str,
																		int i);
int							check_dir(t_instruction *instruction, char *str,
																		int i);
int							check_ind(t_instruction *instruction, char *str,
																		int i);
void						check_label(t_instruction *instruction,
										t_asm *l_asm, char **argv, int argc);
void						error(char *str);
int							rev_end(int val, char size);

void						wr_header(int fd, t_asm *l_asm, t_instruction *ins);
void						wr_ins(int fd, t_instruction *ins);
void						assign_size_ins(t_instruction *ins);
int							get_byte_nb(t_instruction *ins, int i);

void						write_output(char *str, t_asm *l_asm,
															t_instruction *ins);
int							find_label(char *label, char **llabel);
t_asm						*create_str(char *str);
t_asm						*link_str(t_asm *l_asm, char *str);

#endif
