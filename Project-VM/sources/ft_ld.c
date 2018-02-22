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

static int		check_reg(int i, t_data *data)
{
	if (data->arene[i] > 16 || data->arene[i] < 1)
		return (0);
	return (1);
}

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

static int		check_ld(t_cor *proc, t_data *data)
{
	int i;

	i = 0;
	if (proc->param[1] != 4 && proc->param[1] != 2)
		i = ft_count(proc, 2);
	else if (proc->param[2] != 1 || check_reg(proc->ptr + 2 + proc->param[1], data) == 0)
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

void	my_ld(t_data *data, t_cor *proc)
{
	int tab[2];

	//ft_printf("%s player [%d] index = %d tour = %d\n","LD", proc->player, proc->ptr, data->tour);
	//print_tab(data->arene, 4096);
	cal_ocp(proc, data);
	if (check_ld(proc, data) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		tab[0] = data->f2[proc->param[1] - 1](data, proc);
		tab[1] = data->f2[proc->param[2] - 1](data, proc);
		ft_printf("P    %2d | ld %d r%d ptr = %d\n", proc->player, tab[0], tab[1] + 1, proc->ptr);
		if (proc->param[1] == 2)
		{
			tab[0] = take_dir_ind(data, tab[0] % IDX_MOD, proc);
			proc->reg[tab[1]] = tab[0];
		}
		else
			proc->reg[tab[1]] = tab[0];
		(tab[0] == 0 ? (proc->carry = 1) : (proc->carry = 0));
		proc->ptr = proc->pc;
		//print_tab(data->arene, 4096);
	}
}
