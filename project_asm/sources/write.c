/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:12:51 by varichar          #+#    #+#             */
/*   Updated: 2018/03/05 19:23:36 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label_addr(t_instruction *start, t_instruction *ins, char *label,\
		int i)
{
	int addr;

	addr = 0;
	while (start)
	{
		if (find_label(label, start->label))
		{
			if (start->address > ins->address)
			{
				addr = rev_end(start->address - ins->address, (ins->type[i] ==\
							2 && !g_op_tab[(int)(ins->index)].short_dir) ? 4 :\
						2);
			}
			else
			{
				addr = rev_end(start->address - ins->address, 4) >>\
					((ins->type[i] == 2 &&\
						!g_op_tab[(int)(ins->index)].short_dir) ? 0 : 16);
			}
			return (addr);
		}
		start = start->next;
	}
	return (-1);
}

void	wr_ocp(int fd, t_instruction *ins)
{
	char	ocp;
	int		i;

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
	int	i;
	int	wr;

	i = -1;
	while (ins->param[++i] && i < 3)
	{
		if (ins->type[i] == 1)
			wr = (char)ft_atoi(ins->param[i]);
		else if (ins->param[i][0] == ':')
		{
			wr = get_label_addr(start, ins, &(ins->param[i][1]), i);
		}
		else
		{
			wr = ft_atoi(ins->param[i]);
			wr = rev_end(wr, (wr < 0 || (get_byte_nb(ins, i) == 2 && wr >\
				65535)) ? 4 : get_byte_nb(ins, i)) >> ((wr < 0 ||\
				(get_byte_nb(ins, i) == 2 && wr > 65535)) && (ins->type[i] !=\
					2 || g_op_tab[(int)ins->index].short_dir) ? 16 : 0);
		}
		write(fd, &wr, get_byte_nb(ins, i));
	}
}

void	wr_header(int fd, t_asm *l_asm, t_instruction *start)
{
	t_header	h;
	int			i;

	i = 0;
	bzero(&h, sizeof(h));
	h.magic = rev_end(COREWAR_EXEC_MAGIC, 4);
	while (start->next)
		start = start->next;
	h.prog_size = rev_end(start->address + start->size, 4);
	while (l_asm->champname[i])
	{
		ft_strcat(h.prog_name, l_asm->champname[i++]);
		ft_strcat(h.prog_name, (l_asm->champname[i]) ? "\n" : "");
	}
	i = 0;
	while (l_asm->comment[i])
	{
		ft_strcat(h.comment, l_asm->comment[i++]);
		ft_strcat(h.comment, (l_asm->comment[i]) ? "\n" : "");
	}
	write(fd, &h, sizeof(t_header));
}

void	wr_ins(int fd, t_instruction *ins)
{
	int				opcode;
	t_instruction	*start;

	start = ins;
	while (ins && ins->name)
	{
		opcode = ins->index + 1;
		write(fd, &(opcode), 1);
		if (g_op_tab[(int)(ins->index)].ocp)
			wr_ocp(fd, ins);
		wr_param(fd, start, ins);
		ins = ins->next;
	}
}
