/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:57:38 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/25 18:49:05 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../op.h"
# include "../../libft/libft.h"
# include <fcntl.h>

typedef struct	s_asm
{
	char			*str;
	struct s_asm	*next;
}				t_asm;

int					ft_space(char c);
int					is_all_space(char *str);
t_asm				*parse_begin(t_asm *l_asm);
void				parse_instructions(t_asm *tmp);
void				error(char *str);

# endif