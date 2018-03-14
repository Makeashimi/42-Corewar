/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:31:21 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:31:22 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_fork(t_data *data, t_cor *proc)
{
	t_cor			*cor;
	unsigned short	entier;
	int				i;

	i = 0;
	cor = new_proc(data->champ);
	data->nb_champ++;
	cor->player = data->nb_champ;
	proc->pc = (proc->ptr + 1) % MEM_SIZE;
	while (i < 16)
	{
		cor->reg[i] = proc->reg[i];
		i++;
	}
	cor->carry = proc->carry;
	cor->live = proc->live;
	i = 0;
	entier = data->f2[2](data, proc);
	cor->count_t = -1;
	cor->ptr = ((unsigned)proc->ptr + ((short)entier % IDX_MOD)) % MEM_SIZE;
	add_proc(cor, data);
	proc->ptr = proc->pc % MEM_SIZE;
}
