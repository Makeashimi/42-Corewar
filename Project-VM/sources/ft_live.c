/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:29:01 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:29:02 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_live(t_data *data, t_cor *proc)
{
	int entier;

	ft_printf("P    %2d live\n", proc->player);
	proc->pc = (proc->ptr + 1) % MEM_SIZE;
	entier = data->f2[3](data, proc);
	proc->live = proc->live + 1;
	data->last_l =  entier;
	proc->ptr = proc->pc;
}
