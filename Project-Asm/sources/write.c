/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:12:51 by varichar          #+#    #+#             */
/*   Updated: 2018/02/11 16:10:07 by varichar         ###   ########.fr       */
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
		i++;
	}
	write(fd, &ocp, 1);
}

void	wr_param(int fd, t_instruction *ins)
{
	int i;
	(void)fd;
	(void)ins;

	i = 0;
	while (ins->type[i] > 0)
	{
		
		i++;
	}
}

void	wr_header(int fd, t_asm *l_asm)
{
	t_header h;

	bzero(&h, sizeof(h));
	h.magic = rev_end(COREWAR_EXEC_MAGIC, 4);
	h.prog_size = rev_end(23, 4);
	ft_printf("DEBUG - prog_name : \"%s\". \n", l_asm->champname);
	ft_printf("DEBUG - comment : \"%s\". \n", l_asm->comment);
	ft_strcpy(h.prog_name, l_asm->champname);
	ft_strcpy(h.comment, l_asm->comment);
	write(fd, &h, sizeof(t_header));
}

void	wr_ins(int fd, t_instruction *ins)
{
	int	opcode;
	/* DEBUG */
	ins->type[0] = REG_CODE;
	ins->type[1] = DIR_CODE;
	ins->type[2] = DIR_CODE;
	ins->param1 = ft_strdup("1");
	ins->param2 = ft_strdup(":live");
	ins->param3 = ft_strdup("1");
	/* DEBUG */
	while (ins)
	{
		opcode = ins->index + 1;
		write(fd, &(opcode), 1);
		ft_printf("DEBUG - opcode = %d\n", ins->index);
		if (g_op_tab[(int)(ins->index)].ocp)
			wr_ocp(fd, ins);
//		wr_param(fd, ins);
		ins = ins->next;
	}
}

