/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:30:31 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/13 13:30:34 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	my_zjmp(t_data *data, t_cor *proc)
{
	ft_putendl("ZJMP");
	short int index;
	int i;

	i = 0;
	index = 0;
	proc->pc = (proc->ptr + 1) % MEM_SIZE;
	while (i < 2)
	{
		index += data->arene[i + proc->pc] << i * 8;
		i++;
	}
	index = rev_end(index, 2);
	printf("player = %d\n", proc->player);
	printf("%s\n", "bitocul");
	if (proc->carry == 1)
	{
		printf("avant ->%d\n", proc->ptr);
		proc->ptr = (proc->ptr + (index % IDX_MOD)) % MEM_SIZE;
		printf("apres ->%d\n", proc->ptr);
	}
	else
		proc->ptr =  (proc->ptr + 3) % MEM_SIZE;
}
