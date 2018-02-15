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
	//ft_putendl("LIVE");
	int entier = 0;
	int i;

	i = 0;
	proc->ptr = (proc->ptr + 1) % MEM_SIZE;
	while (i++ < 4)
		entier += data->arene[i + proc->ptr] << i * 8;
	entier = rev_end(entier, 4);
	proc->live = proc->live + 1;
	data->last_l =  entier;
	proc->ptr = (proc->ptr + 4) % MEM_SIZE;
}
