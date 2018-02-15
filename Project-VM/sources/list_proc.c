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

t_cor	*new_proc(t_champ *champ)
{
	t_cor	*proc;

	if ((proc = (t_cor *)malloc(sizeof(t_cor))) == NULL)
		return (NULL);
	proc->player = champ->n_p;
	proc->reg[0] = champ->n_p;
	proc->carry = 0;
	proc->live = 0;
	proc->ptr = champ->adr;
	proc->count_t = -1;
	proc->next = NULL;
	return (proc);
}

int		add_proc(t_cor *proc, t_data *data)
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
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = proc;
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
}

void	print_proc(t_cor *proc, t_data *data)
{
	ft_printf("player -> %d\n", proc->player);
	ft_printf("reg [1] = %d\n", proc->reg[0]);
	ft_printf("reg [2] = %d\n", proc->reg[1]);
	ft_printf("reg [3] = %d\n", proc->reg[2]);
	ft_printf("reg [4] = %d\n", proc->reg[3]);
	ft_printf("reg [5] = %d\n", proc->reg[4]);
	ft_printf("reg [6] = %d\n", proc->reg[5]);
	ft_printf("reg [7] = %d\n", proc->reg[6]);
	ft_printf("reg [8] = %d\n", proc->reg[7]);
	ft_printf("reg [9] = %d\n", proc->reg[8]);
	ft_printf("reg [10] = %d\n", proc->reg[9]);
	ft_printf("reg [11] = %d\n", proc->reg[10]);
	ft_printf("reg [12] = %d\n", proc->reg[11]);
	ft_printf("reg [13] = %d\n", proc->reg[12]);
	ft_printf("reg [14] = %d\n", proc->reg[13]);
	ft_printf("reg [15] = %d\n", proc->reg[14]);
	ft_printf("reg [16] = %d\n", proc->reg[15]);
	ft_printf("carry = %d\n", proc->carry);
	ft_printf("live = %d\n", proc->live);
	ft_printf("nombre de tours = %d\n", proc->count_t);
	ft_printf("pointeur = %#x\n", data->arene[proc->ptr]);
	(void)data;
	ft_putchar('\n');
}
