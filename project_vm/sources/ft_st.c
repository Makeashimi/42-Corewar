/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:29:20 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:29:27 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_make(t_data *data, int tab[], t_cor *proc)
{
	data->arene[(unsigned)(proc->ptr + (tab[1] %
	IDX_MOD)) % MEM_SIZE] = (tab[0] & 0xFF000000) >> 24;
	data->arene[(unsigned)(proc->ptr + (tab[1] %
	IDX_MOD) + 1) % MEM_SIZE] = (tab[0] & 0x00FF0000) >> 16;
	data->arene[(unsigned)(proc->ptr + (tab[1] %
	IDX_MOD) + 2) % MEM_SIZE] = (tab[0] & 0x0000FF00) >> 8;
	data->arene[(unsigned)(proc->ptr + (tab[1] %
	IDX_MOD) + 3) % MEM_SIZE] = tab[0] & 0x000000FF;
}

static int		check_st(t_cor *proc, t_data *data)
{
	int i;

	i = 0;
	if (proc->param[1] != 1)
		i = ft_count(proc, 2);
	else if (proc->param[2] != 2 && proc->param[2] != 1)
		i = ft_count(proc, 2);
	else if (check_reg(data, proc, 2) != 0)
		i = check_reg(data, proc, 2);
	if (i != 0)
		proc->ptr = (proc->ptr + i) % MEM_SIZE;
	return (i);
}

void			my_st(t_data *data, t_cor *proc)
{
	int tab[2];

	cal_ocp(proc, data);
	proc->pc = proc->ptr;
	if (check_st(proc, data) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		tab[0] = data->f2[proc->param[1] - 1](data, proc);
		tab[1] = data->f2[proc->param[2] - 1](data, proc);
		tab[0] = proc->reg[tab[0]];
		if (proc->param[2] == 1)
			proc->reg[tab[1]] = tab[0];
		else
			ft_make(data, tab, proc);
		proc->ptr = proc->pc;
	}
}
