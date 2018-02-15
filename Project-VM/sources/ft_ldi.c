/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:05:28 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/15 14:23:26 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_ldi(t_data *data, t_cor *proc)
{
	int	address;
	int	address2;
	int type[2];
	int	i;

	address = 0;
	i = -1;
	cal_ocp(proc, data);
	proc->pc = proc->ptr;
	proc->pc = (proc->pc + 2) % MEM_SIZE; 
	while (++i < proc->param[1])
		address += data->arene[proc->pc + i] << i * 8;
	address = rev_end(address, proc->param[1]);
	proc->pc += proc->param[1];
	i = -1;
	while (++i < proc->param[2])
		address2 += data->arene[proc->pc + i] << i * 8; 
	address += rev_end(address2, proc->param[2]);


}
