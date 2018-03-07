/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:19:42 by thbricqu          #+#    #+#             */
/*   Updated: 2018/02/15 14:19:45 by thbricqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_and(t_cor *proc, t_data *data)
{
	int i;

	i = 0;
	if (proc->param[1] != 1 && proc->param[1] != 2 && proc->param[1] != 4)
		i = ft_count(proc, 3);
	else if (proc->param[2] != 1 && proc->param[2] != 2 && proc->param[2] != 4)
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

void			my_and(t_data *data, t_cor *proc)
{
	int	param[3];

	cal_ocp(proc, data);
	if (check_and(proc, data) == 0)
	{
		proc->pc = (proc->ptr + 2) % MEM_SIZE;
		param[0] = data->f2[proc->param[1] - 1](data, proc);
		param[1] = data->f2[proc->param[2] - 1](data, proc);
		param[2] = data->f2[proc->param[3] - 1](data, proc);
		if (proc->param[1] == 1)
			param[0] = proc->reg[param[0]];
		if (proc->param[2] == 1)
			param[1] = proc->reg[param[1]];
		if (proc->param[1] == 2)
			param[0] = take_dir_ind(data, param[0] % IDX_MOD, proc);
		if (proc->param[2] == 2)
			param[1] = take_dir_ind(data, param[1] % IDX_MOD, proc);
		proc->reg[param[2]] = param[0] & param[1];
		ft_carry(proc, proc->reg[param[2]]);
		proc->ptr = proc->pc;
	}
}
