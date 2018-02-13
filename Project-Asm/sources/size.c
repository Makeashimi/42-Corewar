/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:30:18 by varichar          #+#    #+#             */
/*   Updated: 2018/02/13 15:24:45 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	assign_size_ins(t_instruction *ins)
{
	int		offset;
	int		i;

	offset = 0;
	while (ins)
	{
		ins->address = offset;
		ins->size = 0;
		ins->size += 1;
		ins->size += (g_op_tab[(int)ins->index].ocp ? 1 : 0);
		i = 0;
		while (ins->param[i])
		{
			ins->size += (ins->type[i] == 1) ? 1 : 0;
			if (ins->type[i] == 2)
				ins->size += (g_op_tab[(int)ins->index].short_dir) ? 2 : 4;
			ins->size += (ins->type[i] == 3) ? 2 : 0;
			i++;
		}
		offset += ins->size;
		ins = ins->next;
	}
}

int		get_byte_nb(t_instruction *ins, int i)
{
	return ((ins->type[i] == 2 && !g_op_tab[(int)(ins->index)].short_dir) ?\
			4 : 2);
}
