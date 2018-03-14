/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:48:43 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/16 11:48:45 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		take_ind(t_data *data, t_cor *proc)
{
	int index;
	int i;

	i = 0;
	index = 0;
	while (i < 2)
	{
		index += data->arene[(i + proc->pc) % MEM_SIZE] << i * 8;
		i++;
	}
	index = rev_end(index, 2);
	proc->pc = (proc->pc + 2) % MEM_SIZE;
	return ((short)index);
}

int		take_dir(t_data *data, t_cor *proc)
{
	int index;
	int i;

	index = 0;
	i = 0;
	while (i < 4)
	{
		index += data->arene[(i + proc->pc) % MEM_SIZE] << i * 8;
		i++;
	}
	index = rev_end(index, 4);
	proc->pc = (proc->pc + 4) % MEM_SIZE;
	return (index);
}

int		take_dir_short(t_data *data, t_cor *proc)
{
	int index;
	int i;

	index = 0;
	i = 0;
	while (i < 2)
	{
		index += data->arene[(i + proc->pc) % MEM_SIZE] << i * 8;
		i++;
	}
	index = rev_end(index, 2);
	proc->pc = (proc->pc + 2) % MEM_SIZE;
	return ((short)index);
}

int		take_reg(t_data *data, t_cor *proc)
{
	int i;

	i = (int)data->arene[proc->pc] - 1;
	proc->pc = (proc->pc + 1) % MEM_SIZE;
	return (i);
}
