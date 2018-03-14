/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:32:01 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:32:05 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_lfork(t_data *data, t_cor *proc)
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
	entier = data->f2[2](data, proc);
	cor->ptr = ((unsigned)proc->ptr + ((entier))) % MEM_SIZE;
	cor->count_t = -1;
	add_proc(cor, data);
	proc->ptr = (proc->pc) % MEM_SIZE;
}
