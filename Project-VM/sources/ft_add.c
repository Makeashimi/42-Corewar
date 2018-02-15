/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:29:35 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:29:36 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_add(t_data *data, t_cor *proc)
{
	//ft_putendl("ADD");
	int a;
	int b;
	int c;

	cal_ocp(proc, data);
	proc->pc = (proc->ptr + 2) % MEM_SIZE;
	a = (int)data->arene[proc->pc];
	proc->pc = (proc->ptr + 1) % MEM_SIZE;
	b = (int)data->arene[proc->pc];
	proc->pc = (proc->ptr + 1) % MEM_SIZE;
	c = (int)data->arene[proc->pc];
	proc->pc = (proc->ptr + 1) % MEM_SIZE;
	proc->reg[c] = proc->reg[a] + proc->reg[b];
	proc->ptr = proc->pc;
	(proc->carry == 1 ? (proc->carry = 0) : (proc->carry = 1));
}
