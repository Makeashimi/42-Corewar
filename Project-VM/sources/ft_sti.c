/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:31:05 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:31:06 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


static void		my_sti_1(t_data *data, t_cor *proc)
{
	int a;
	int b;
	int c;
	char *cop;

	proc->pc = proc->ptr;
	proc->pc = (proc->pc + 2) % MEM_SIZE;
	a = (int)proc->pc;
	b = (int)(proc->pc + 1);
	c = (int)(proc->pc + 2);
	cop = ft_itoabase(proc->reg[a], 16);
	ft_memcpy(&data[(b + c) % MEM_SIZE], cop, 4);
	free(cop);
	proc->ptr = (proc->ptr + 5) % MEM_SIZE;
}

static void		my_sti_2(t_data *data, t_cor *proc)
{

}

void	my_sti(t_data *data, t_cor *proc)
{
	cal_ocp(proc, data);
	if (param[2] == 1 && param[3] == 1)
		my_sti_1(data, proc);
	else if (param[2] == 1 && param[3] == 2)
		my_sti_2(data, proc);
	else if (param[2] == 2 && param[3] == 1)
		my_sti_3(data, proc);
	else
		my_sti_4(data, proc);
}
