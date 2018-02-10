/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:12:51 by varichar          #+#    #+#             */
/*   Updated: 2018/02/10 19:20:43 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	wr_ocp(int fd, t_instruction *ins)
{
	char ocp;
	int i;

	ocp = 0;
	i = 0;
	while (i < 3)
	{
		if (ins->type[i] > 0)
			ocp = (ocp | ins->type[i]);
		ocp = ocp << 2;
	}
	write(fd, &ocp, 1);
}

void	wr_param(int fd, t_instruction *ins)
{
	int i;
	(void)fd;
	(void)ins;

	i = 0;
	while (i < 3)
	{
	
	}
}

void	wr_header(int fd, t_asm *l_asm)
{
	t_header h;

	h.magic = rev_end(COREWAR_EXEC_MAGIC, 4);
	bzero(h.prog_name, PROG_NAME_LENGTH + 1);
	bzero(h.comment, COMMENT_LENGTH + 1);
	h.prog_size = rev_end(23, 4);
	while (l_asm)
	{
		ft_printf("%s\n", l_asm->str);
		l_asm = l_asm->next;
	}
	write(fd, &h, sizeof(t_header));
}

void	wr_ins(int fd, t_instruction *ins)
{
	while (ins)
	{
		write(fd, &(ins->index), 1);
		if (g_op_tab[(int)(ins->index)].ocp)
			wr_ocp(fd, ins);
//		wr_param(fd, ins);
	}
}

