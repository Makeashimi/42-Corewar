/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:29:35 by thedupuy          #+#    #+#             */
/*   Updated: 2018/03/07 16:47:25 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_add(t_cor *proc, t_data *data)
{
	int i;

	i = 0;
	if (proc->param[1] != 1)
		i = ft_count(proc, 3);
	else if (proc->param[2] != 1)
		i = ft_count(proc, 3);
	else if (proc->param[3] != 1)
		i = ft_count(proc, 3);
	else if (check_reg(data, proc, 3) != 0)
		i = ft_count(proc, 3);
	if (i != 0)
		proc->ptr = (proc->ptr + i) % MEM_SIZE;
	return (i);
}

void		my_add(t_data *data, t_cor *proc)
{
	int tab[3];

	cal_ocp(proc, data);
	if (check_add(proc, data) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		tab[0] = (int)data->arene[proc->pc];
		tab[1] = (int)data->arene[(proc->pc + 1) % MEM_SIZE];
		tab[2] = (int)data->arene[(proc->pc + 2) % MEM_SIZE];
		proc->reg[tab[2] - 1] = proc->reg[tab[0] - 1] + proc->reg[tab[1] - 1];
		proc->ptr = (proc->ptr + 5) % MEM_SIZE;
		if (proc->reg[tab[2] - 1] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
}
