/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:12:51 by varichar          #+#    #+#             */
/*   Updated: 2018/02/11 18:39:12 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label_addr(t_instruction *start, t_instruction *ins, char *label)
{
	int addr;

	addr = 0;
	while (start)
	{
		if (ft_strcmp(start->label, label) == 0)
			return (start->address);
		start = start->next;
	}
	return (-1);
}

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

void	wr_param(int fd, t_instruction *start, t_instruction *ins)
{
	int i;
	int	wr;
	int	l;

	i = 0;
	while (ins->param[i])
	{
		if (ins->type[i] == 1)
		{
			wr = ft_atoi(ins->param[i]);
			l = 1;
		}
		else if (ins->param[i][0] == ':')
		{
			wr = rev_end(get_label_addr(start, ins, &(ins->param[i][1])),\
					(ins->type[i] == 2 &&\
					 !g_op_tab[(int)(ins->index)].short_dir) ? 4 : 2);
			l = (ins->type[i] == 2 &&\
					!g_op_tab[(int)(ins->index)].short_dir) ? 4 : 2;
		}
		write(fd, &wr, l);
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
	t_instruction *start;
	/* DEBUG */
	ins->type[0] = REG_CODE;
	ins->type[1] = DIR_CODE;
	ins->type[2] = DIR_CODE;
	ins->param[0]= ft_strdup("1");
	ins->param[1] = ft_strdup(":live");
	ins->param[2] = ft_strdup("1");
	/* DEBUG */
	assign_size_ins(ins);
	start = ins;
	while (ins)
	{
		ft_printf("DEBUG - address ins : %d\n", ins->address);
		opcode = ins->index + 1;
		write(fd, &(opcode), 1);
		ft_printf("DEBUG - opcode = %d\n", ins->index);
		if (g_op_tab[(int)(ins->index)].ocp)
			wr_ocp(fd, ins);
		wr_param(fd, start, ins);
		ins = ins->next;
	}
}

