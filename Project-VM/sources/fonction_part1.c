/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:39:17 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/09 13:39:19 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_zjump(t_cor *proc)
{


	if (proc->carry == 1)
	{
		proc->ptr = proc->ptr + (short)proc->param[0] % IDX_MOD;
	}
	proc->param[0] = 0;
	proc->param[1] = 0;
	proc->param[2] = 0;
	proc->param[3] = 0;
}
