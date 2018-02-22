/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:30:31 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:30:34 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_zjmp(t_data *data, t_cor *proc)
{
	short int index;
	int i;

	i = 0;
	proc->pc = (proc->ptr + 1) % MEM_SIZE;
	index = data->f2[2](data, proc);
	if (proc->carry == 1)
	{
		ft_printf("P    %2d | zjmp %d OK\n", proc->player, (proc->ptr + (index % IDX_MOD)) % MEM_SIZE - proc->ptr);
		proc->ptr = (proc->ptr + (index % IDX_MOD)) % MEM_SIZE;
	}
	else
	{
		ft_printf("P    %2d | zjmp %d FAILED  ptr = %d\n", proc->player, (proc->ptr + index) % MEM_SIZE - proc->ptr, proc->ptr);
		proc->ptr =  proc->pc;
	}
}
