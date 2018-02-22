/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:29:43 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:29:45 by thedupuy         ###   ########.fr       */
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

static int 	check_sub(t_cor *proc)
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

void	my_sub(t_data *data, t_cor *proc)
{
	int tab[3];

	ft_printf("%s player [%d]\n","SUB", proc->player);
	cal_ocp(proc, data);
	if (check_sub(proc) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		tab[0] = (int)data->arene[proc->pc];
		tab[1] = (int)data->arene[proc->pc + 1];
		tab[2] = (int)data->arene[proc->pc + 2];
		proc->reg[tab[2] - 1] = proc->reg[tab[0] - 1] - proc->reg[tab[1] - 1];
		proc->ptr = (proc->ptr + 5) % MEM_SIZE;
		(proc->reg[tab[2] - 1] == 0 ? (proc->carry = 1) : (proc->carry = 0));
	}
}
