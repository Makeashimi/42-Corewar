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

static int ft_count(t_cor *proc, int p)
{
	int i;
	int x;

	i = 2;
	x = 1;
	while (x <= p)
	{
		if (proc->param[x] == 3)
			i = i + 2;
		else
			i = i + proc->param[x];
		x++;
	}
	return (i);
}

static int 	check_add(t_cor *proc)
{
	int i;

	i = 0;
	if (proc->param[1] != 1)
		i = ft_count(proc, 3);
	else if (proc->param[2] != 1)
		i = ft_count(proc, 3);
	else if (proc->param[3] != 1)
		i = ft_count(proc, 3);
	if (i != 0)
		proc->ptr = (proc->ptr + i) % MEM_SIZE;
	return (i);
}

void		my_add(t_data *data, t_cor *proc)
{
	int tab[3];

	cal_ocp(proc, data);
	ft_printf("add. ptr =%d tour =%d\n", proc->ptr, data->tour);
	if (check_add(proc) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		tab[0] = (int)data->arene[proc->pc];
		tab[1] = (int)data->arene[(proc->pc + 1) % MEM_SIZE];
		tab[2] = (int)data->arene[(proc->pc + 2) % MEM_SIZE];
		proc->reg[tab[2]] = proc->reg[tab[0]] + proc->reg[tab[1]];
		proc->ptr = (proc->ptr + 5) % MEM_SIZE;
		(proc->reg[tab[2] - 1] == 0 ? (proc->carry = 1) : (proc->carry = 0));
	}
	ft_printf("add. ptr =%d tour =%d\n", proc->ptr, data->tour);
}
