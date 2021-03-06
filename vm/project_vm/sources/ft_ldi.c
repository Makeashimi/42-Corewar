/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:05:28 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 14:05:29 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_ldi(t_cor *proc, t_data *data)
{
	int i;

	i = 0;
	if (proc->param[1] != 1 && proc->param[1] != 2 && proc->param[1] != 3)
		i = ft_count(proc, 3);
	else if (proc->param[2] != 3 && proc->param[2] != 1)
		i = ft_count(proc, 3);
	else if (proc->param[3] != 1)
		i = ft_count(proc, 3);
	else if (check_reg(data, proc, 3) != 0)
		i = check_reg(data, proc, 3);
	if (i != 0)
		proc->ptr = (proc->ptr + i) % MEM_SIZE;
	return (i);
}

static int		take_dir_ind(t_data *data, int add, t_cor *proc)
{
	int index;
	int i;

	index = 0;
	i = 0;
	while (i < 4)
	{
		index += data->arene[(i + proc->ptr + add) % MEM_SIZE] << i * 8;
		i++;
	}
	index = rev_end(index, 4);
	return (index);
}

void			my_ldi(t_data *data, t_cor *proc)
{
	int tab[3];

	cal_ocp(proc, data);
	if (check_ldi(proc, data) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		tab[0] = data->f2[proc->param[1] - 1](data, proc);
		tab[1] = data->f2[proc->param[2] - 1](data, proc);
		tab[2] = data->f2[proc->param[3] - 1](data, proc);
		if (proc->param[2] == 1)
			tab[1] = proc->reg[tab[1]];
		if (proc->param[1] == 1)
			tab[0] = proc->reg[tab[0]];
		if (proc->param[1] == 2)
			tab[0] = take_dir_ind(data, tab[0] % IDX_MOD, proc);
		proc->reg[tab[2]] = take_dir_ind(data,
		(tab[0] + tab[1]) % IDX_MOD, proc);
		proc->ptr = proc->pc;
	}
}
