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
	if (!(champ->name = (unsigned char *)malloc(sizeof(unsigned char) * x)))
		return (-1);
	ft_memcpy(champ->name, &tab[i], (size_t)x);
	champ->size_nm = x;
	i = i + x;
	x = 0;
	while (tab[i] == 0x00)
		i++;
	while (tab[i + x] != 0x00)
		x++;
	if (!(champ->com = (unsigned char *)malloc(sizeof(unsigned char) * x)))
		return (-1);
	ft_memcpy(champ->com, &tab[i], (size_t)x);
	champ->size_cm = x;
	return (1);
}

void	check_live(t_data *data, t_cor *tmp, t_cor *tmp2)
{
	tmp = data->proc;
	while (tmp)
	{
		if (tmp->live < 1)
		{
			if (tmp2)
			{
				tmp2->next = tmp->next;
				free(tmp);
				tmp = tmp2->next;
			}
			else
			{
				data->proc = tmp->next;
				free(tmp);
				tmp = data->proc;
			}
		}
		else
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
	}
}

int		check_nb_live(t_data *data)
{
	t_cor	*tmp;
	int		i;

	i = 0;
	tmp = data->proc;
	while (tmp)
	{
		i = i + tmp->live;
		tmp->live = 0;
		tmp = tmp->next;
	}
	return (i);
}

void	check_to_die(t_data *data)
{
	t_cor *tmp;
	t_cor *tmp2;

	tmp = NULL;
	tmp2 = NULL;
	check_live(data, tmp, tmp2);
	if ((check_nb_live(data) >= NBR_LIVE) ||
		data->nbr_c == MAX_CHECKS)
	{
		data->nbr_c = 0;
		data->ctd = data->ctd - CYCLE_DELTA;
	}
	else
		data->nbr_c++;
}
