/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:29:11 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:29:13 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_ld(t_cor *proc, t_data *data)
{
	int i;

	i = 0;
	if (proc->param[1] != 4 && proc->param[1] != 2)
		i = ft_count(proc, 2);
	else if (proc->param[2] != 1)
		i = ft_count(proc, 2);
	else if (check_reg(data, proc, 2) != 0)
		i = check_reg(data, proc, 2);
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

void			my_ld(t_data *data, t_cor *proc)
{
	int tab[2];

	cal_ocp(proc, data);
	if (check_ld(proc, data) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		tab[0] = data->f2[proc->param[1] - 1](data, proc);
		tab[1] = data->f2[proc->param[2] - 1](data, proc);
		if (proc->param[1] == 2)
		{
			tab[0] = take_dir_ind(data, tab[0] % IDX_MOD, proc);
			proc->reg[tab[1]] = tab[0];
		}
		else
			proc->reg[tab[1]] = tab[0];
		if (tab[0] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
		proc->ptr = proc->pc;
	}
}
