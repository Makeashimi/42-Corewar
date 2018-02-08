/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:11:09 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/06 20:11:11 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_player(t_data *data)
{
	int i;

	i = 0;
	if (data->n == 1)
	{
		while (data->c_n[i] == 0)
			i++;
		if (i == data->nb_champ)
			return (1);
		else
			return (-1);
	}
	return (1);
}

int		ft_take_name_com(t_champ *champ, unsigned char tab[])
{
	int i;
	int x;

	i = 4;
	x = 0;
	while (tab[i + x] != 0x00)
		x++;
	if ((champ->name = (unsigned char *)malloc(sizeof(unsigned char) * x)) == NULL)
		return (-1);
	ft_memcpy(champ->name, &tab[i], (size_t)x);
	champ->size_nm = x;
	i = i + x;
	x = 0;
	while (tab[i] == 0x00)
		i++;
	while (tab[i + x] != 0x00)
		x++;
	if ((champ->com = (unsigned char *)malloc(sizeof(unsigned char) * x)) == NULL)
		return (-1);
	ft_memcpy(champ->com, &tab[i], (size_t)x);
	champ->size_cm = x;
	return (1);
}