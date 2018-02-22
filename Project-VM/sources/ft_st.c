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

// static int		check_reg(int i, t_data *data)
// {
// 	if (data->arene[i] > 16 || data->arene[i] < 1)
// 		return (0);
// 	return (1);
// }

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

static int	check_st(t_cor *proc)
{
	int i;

	i = 0;
	//ft_printf("P    %2d, param1 = %d param2 = %d param3 = %d\n", proc->player, proc->param[0], proc->param[1], proc->param[4]);
	if (proc->param[1] != 1)
		i = ft_count(proc, 2);
	else if (proc->param[2] != 2 && proc->param[2] != 1)
		i = ft_count(proc, 2);
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

void	my_st(t_data *data, t_cor *proc)
{
	int tab[2];

	cal_ocp(proc, data);
	proc->pc = proc->ptr;
	if (check_st(proc) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		tab[0] = data->f2[proc->param[1] - 1](data, proc);
		tab[1] = data->f2[proc->param[2] - 1](data, proc);
		ft_printf("P    %2d | st r%d %d ptr = %d tour = %d\n", proc->player, tab[0] + 1, (proc->ptr + (tab[1] % IDX_MOD)) % MEM_SIZE - proc->ptr, proc->ptr, data->tour);
		tab[0] = proc->reg[tab[0]];
		if (proc->param[2] == 1)
			proc->reg[tab[1]] = tab[0];
		else
		{
			tab[1] = take_dir_ind(data, tab[1] % IDX_MOD, proc);
			data->arene[(unsigned)(proc->ptr + (tab[1] % IDX_MOD)) % MEM_SIZE] = (tab[0] & 0xFF000000) >> 24;
			data->arene[(unsigned)(proc->ptr + (tab[1] % IDX_MOD) + 1) % MEM_SIZE] = (tab[0] & 0x00FF0000) >> 16;
			data->arene[(unsigned)(proc->ptr + (tab[1] % IDX_MOD) + 2) % MEM_SIZE] = (tab[0] & 0x0000FF00) >> 8;
			data->arene[(unsigned)(proc->ptr + (tab[1] % IDX_MOD) + 3) % MEM_SIZE] = tab[0] & 0x000000FF;
		}
		proc->ptr = proc->pc;
	}
	else
		ft_printf("P    %2d  loose | [ proc->ptr = %d ] [ proc->pc = %d ] [ param1 = %d ] [ param2 = %d ] [ param3 = %d ]\n", proc->player, proc->ptr, proc->pc, proc->param[0], proc->param[1], proc->param[2]);		
}
