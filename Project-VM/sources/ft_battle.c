/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_battle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:00:47 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/09 15:00:52 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	battle(t_data *data)
{
	t_cor	*tmp;

	tmp = data->proc;
	while (tmp)
	{
		if (tmp->count_t == -1)
			check_inst(tmp, data);
		else if (tmp->count_t == 0)
		{
			(data->f[tmp->inst - 1](data, tmp));
			tmp->count_t = -1;
			tmp->ptr = (tmp->ptr + 1) % MEM_SIZE;
		}
		else
			tmp->count_t--;
		tmp = tmp->next;
	}
}

void		check_inst(t_cor *proc, t_data *data)
{
	if (data->arene[proc->ptr] > 0x10 || data->arene[proc->ptr] < 0x01)
		proc->ptr = (proc->ptr + 1 ) % MEM_SIZE;
	else
	{
		proc->inst = (int)data->arene[proc->ptr];
		proc->count_t = g_op_tab[data->arene[proc->ptr] - 1].nb_cycle;
	}
}

void		print_bits(unsigned char octet, char tab[])
{
	int		oct;
	int		div;
	int		i;

	i = 0;
	tab[8] = '\0';
	div = 128;
	oct = octet;
	while (div != 0)
	{
		if (div <= oct)
		{
			tab[i++] = '1';
			oct = oct % div;
		}
		else
			tab[i++] = '0';
		div = div / 2;
	}
}