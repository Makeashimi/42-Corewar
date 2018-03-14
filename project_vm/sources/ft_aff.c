/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:32:11 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:32:13 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_aff(t_cor *proc, t_data *data)
{
	int i;

	i = 0;
	if (proc->param[1] != 1)
		i = ft_count(proc, 1);
	else if (check_reg(data, proc, 1) != 0)
		i = check_reg(data, proc, 1);
	if (i != 0)
		proc->ptr = (proc->ptr + i) % MEM_SIZE;
	return (i);
}

void			my_aff(t_data *data, t_cor *proc)
{
	int i;

	cal_ocp(proc, data);
	if (check_aff(proc, data) == 0)
	{
		proc->ptr = (proc->ptr + 2) % MEM_SIZE;
		i = (int)data->arene[proc->ptr];
		i = proc->reg[i - 1];
		ft_putchar(i % 256);
		proc->ptr = (proc->ptr + 1) % MEM_SIZE;
	}
}
