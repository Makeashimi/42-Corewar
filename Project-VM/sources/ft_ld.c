/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:29:11 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/15 14:18:01 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		my_second_ld(t_data *data, t_cor *proc)
{
	int i;
	int entier;
	short int index;

	i = 0;
	entier = 0;
	index = 0;
	while (i < 2)
	{
		index += data->arene[i + proc->pc] << i * 8;
		i++;
	}
	index = rev_end(entier, 2);
	proc->pc = (proc->pc + 2) % MEM_SIZE;
	proc->pc = ((proc->pc + (index % IDX_MOD)) % MEM_SIZE);
	i = 0;
	while (i < 4)
	{
		entier += data->arene[i + proc->pc] << i * 8;
		i++;
	}
	entier = rev_end(entier, 4);
	proc->reg[data->arene[proc->pc] - 1] = entier;
	proc->ptr = (proc->pc + 1) % MEM_SIZE;
}

void	my_ld(t_data *data, t_cor *proc)
{
	//ft_putendl("LD");
	int entier;
	int i;

	i = 0;
	entier = 0;
	cal_ocp(proc, data);
	proc->pc = proc->ptr;
	proc->pc = (proc->pc + 2) % MEM_SIZE;
	if (proc->param[1] == 4)
	{
		while (i < 4)
		{
			entier += data->arene[i + proc->pc] << i * 8;
			i++;
		}
		entier = rev_end(entier, 4);
		proc->pc = (proc->pc + 4) % MEM_SIZE;
		proc->reg[data->arene[proc->pc] - 1] = entier;
		proc->ptr = (proc->pc + 1) % MEM_SIZE;
	}
	else if (proc->param[1] == 2)
		my_second_ld(data, proc);
	(proc->carry == 1 ? (proc->carry = 0) : (proc->carry = 1));
}
