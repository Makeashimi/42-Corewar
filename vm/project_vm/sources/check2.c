/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 09:43:54 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/22 09:43:56 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_count(t_cor *proc, int p)
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

int		check_reg(t_data *data, t_cor *proc, int p)
{
	int i;
	int x;

	i = 2;
	x = 1;
	while (x <= p)
	{
		if (proc->param[x] == 1)
		{
			if (data->arene[(proc->ptr + i) % MEM_SIZE] > 16 ||
			data->arene[(proc->ptr + i) % MEM_SIZE] < 1)
				return (ft_count(proc, p));
			i = i + 1;
		}
		else if (proc->param[x] == 3)
			i = i + 2;
		else
			i = i + proc->param[x];
		x++;
	}
	return (0);
}

void	ft_carry(t_cor *proc, int i)
{
	if (i == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
