/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:28:08 by thbricqu          #+#    #+#             */
/*   Updated: 2018/02/15 14:28:11 by thbricqu         ###   ########.fr       */
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

static int	check_xor(t_cor *proc)
{
	int i;

	i = 0;
	if (proc->param[1] != 1 && proc->param[1] != 2 && proc->param[1] != 4)
		i = ft_count(proc, 3);
	else if (proc->param[2] != 1 && proc->param[2] != 2 && proc->param[2] != 4)
		i = ft_count(proc, 3);
	else if (proc->param[3] != 1)
		i = ft_count(proc, 3);
	if (i != 0)
		proc->ptr = (proc->ptr + i) % MEM_SIZE;
	return (i);
}

void	my_xor(t_data *data, t_cor *proc)
{
	int	param[3];

	cal_ocp(proc, data);
	if (check_xor(proc) == 0)
	{
		ft_printf("%s player [%d] param[1] = %d param[2] = %d param[3] = %d ptr = %d\n","XOR", proc->player, proc->param[1], proc->param[2], proc->param[3], proc->ptr);
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		param[0] = data->f2[proc->param[1] - 1](data, proc);
		param[1] = data->f2[proc->param[2] - 1](data, proc);
		param[2] = data->f2[proc->param[3] - 1](data, proc);
		proc->reg[param[2]] = proc->reg[param[0]] ^ proc->reg[param[1]];
		(proc->reg[param[2]] == 0 ? (proc->carry = 1) : (proc->carry = 0));
		proc->ptr = proc->pc;
	}
}
