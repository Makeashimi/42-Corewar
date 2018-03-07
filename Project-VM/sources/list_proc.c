/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 10:36:38 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/09 10:36:41 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cor		*new_proc(t_champ *champ)
{
	t_cor	*proc;

	if ((proc = (t_cor *)malloc(sizeof(t_cor))) == NULL)
		return (NULL);
	proc->player = champ->n_p;
	proc->reg[0] = -champ->n_p;
	proc->carry = 0;
	proc->live = 0;
	proc->ptr = champ->adr;
	proc->pc2 = champ->adr;
	proc->count_t = -1;
	proc->next = NULL;
	return (proc);
}

int			add_proc(t_cor *proc, t_data *data)
{
	t_cor *tmp;

	if (proc == NULL)
		return (-1);
	if (data->proc == NULL)
	{
		data->proc = proc;
		return (1);
	}
	else
	{
		tmp = data->proc;
		data->proc = proc;
		data->proc->next = tmp;
		return (1);
	}
}

void		init_instruction(t_data *data)
{
	data->f[0] = my_live;
	data->f[1] = my_ld;
	data->f[2] = my_st;
	data->f[3] = my_add;
	data->f[4] = my_sub;
	data->f[5] = my_and;
	data->f[6] = my_or;
	data->f[7] = my_xor;
	data->f[8] = my_zjmp;
	data->f[9] = my_ldi;
	data->f[10] = my_sti;
	data->f[11] = my_fork;
	data->f[12] = my_lld;
	data->f[13] = my_lldi;
	data->f[14] = my_lfork;
	data->f[15] = my_aff;
	data->f2[0] = take_reg;
	data->f2[1] = take_ind;
	data->f2[2] = take_dir_short;
	data->f2[3] = take_dir;
}
