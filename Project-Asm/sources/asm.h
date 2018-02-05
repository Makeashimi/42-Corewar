/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:57:38 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/05 21:49:20 by jcharloi         ###   ########.fr       */
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
	int						index_instruction;
	struct s_instruction	*next;
}							t_instruction;

typedef struct				s_asm
{
	char					*str;
	t_instruction			*instruction;
	//char					*label;
	struct s_asm			*next;
}							t_asm;

int							ft_space(char c);
int							is_all_space(char *str);
t_asm						*parse_begin(t_asm *l_asm);
void						parse_instructions(t_asm *l_asm, t_asm *tmp);
void						error(char *str);

# endif