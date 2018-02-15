/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:29:20 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:29:27 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_st(t_data *data, t_cor *proc)
{
	//ft_putendl("ST");
	char *cop;
	short int index;
	int i;

	index = 0;
	i = 0;
	cal_ocp(proc, data);
	proc->pc = (proc->ptr + 2) % MEM_SIZE;
	if (proc->param[2] == 1)
		proc->reg[data->arene[proc->pc + 1]] = proc->reg[data->arene[proc->pc]];
	else
	{
		cop = ft_itoabase(proc->reg[data->arene[proc->ptr]], 16);
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		while (i < 2)
		{
			index += data->arene[i + proc->pc] << i * 8;
			i++;
		}
		index = rev_end(index, 2);
		proc->pc = (proc->pc + 2) % MEM_SIZE;
		ft_memcpy(&data->arene[(proc->ptr + (index % IDX_MOD)) % MEM_SIZE], (void *)cop, 4);
		free(cop);
	}
	proc->ptr = (proc->pc + 1) % MEM_SIZE;
}
