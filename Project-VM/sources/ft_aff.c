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

void	my_aff(t_data *data, t_cor *proc)
{
	int i;

	ft_printf("%s player [%d], ptr = %d\n","AFF", data->tour, proc->ptr);
	proc->ptr = (proc->ptr + 2) % MEM_SIZE;
	i = data->arene[proc->ptr];
	i = proc->reg[i - 1];
	//ft_putchar(i % 256);
	//proc->ptr = (proc->ptr + 1) % MEM_SIZE;	
}
