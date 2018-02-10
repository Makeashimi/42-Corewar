/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:12:51 by varichar          #+#    #+#             */
/*   Updated: 2018/01/25 19:40:57 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	wr_ocp(int fd, t_instruction *ins)
{
	char ocp;
	int i;

	ocp = 0;
	i = 0;
	while (i < 3 && ins->type[i] > 0)
	{
		if (ins->type[i] > 0)
			ocp = (ocp | ins->type[i]);
		ocp = ocp << 2;
	}
	write(fd, &ocp, 1);
}

void	wr_header(int fd, t_header *h)
{
	write(fd, h, sizeof(t_header));
}

void	wr_ins(int fd, t_instruction *ins)
{
	write(fd, ins->index, 1);
	if (g_op_tab[ins->index].ocp)
		wr_ocp(fd, ins);
	wr_param(int fd, ins);
}

