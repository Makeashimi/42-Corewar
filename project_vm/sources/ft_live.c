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
	int		entier;
	int		i;
	t_champ	*champ;

	champ = data->champ;
	proc->pc = (proc->ptr + 1) % MEM_SIZE;
	entier = data->f2[3](data, proc);
	proc->live = proc->live + 1;
	entier = entier * -1;
	if (entier > 0 && entier <= data->nb_champ2)
	{
		data->last_l = entier;
		i = entier;
		while (i != champ->n_p)
			champ = champ->next;
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
		entier, champ->name);
	}
	proc->ptr = proc->pc;
}
