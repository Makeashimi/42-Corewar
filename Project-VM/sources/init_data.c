/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:02:45 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/06 17:02:47 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_data		*init_data()
{
	t_data *data;

	if ((data = (t_data *)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	if ((data->arene = (unsigned char *)malloc(sizeof(unsigned char) * 4096))
		== NULL)
		return (NULL);
	ft_memset(data->arene, 0, 4096);
	data->champ = NULL;
	data->proc = NULL;
	data->verb = 0;
	data->dump = -1;
	data->nb_champ = 0;
	data->n = 0;
	data->c_n[0] = 1;
	data->c_n[1] = 2;
	data->c_n[2] = 3;
	data->c_n[3] = 4;
	return (data);
}

t_champ		*new_champ()
{
	t_champ	*champ;

	if ((champ = (t_champ *)malloc(sizeof(t_champ))) == NULL)
		return (NULL);
	champ->n_p = 0;
	champ->name = NULL;
	champ->com = NULL;
	champ->code = NULL;
	champ->next = NULL;
	return (champ);
}

void	add_champ(t_champ *new, t_data *data)
{
	t_champ *tmp;

	if (data->champ == NULL)
		data->champ = new;
	else
	{
		tmp = data->champ;
		data->champ = new;
		data->champ->next = tmp;
	}
}

void	init_champ(t_data *data)
{
	t_champ *tmp;
	int		i;

	i = 1;
	tmp = data->champ;
	if (data->n == 0)
	{
		while (tmp)
		{
			tmp->n_p = i;
			i++;
			tmp = tmp->next;
		}
		tmp = data->champ;
	}
	while (tmp)
	{	
		ft_memcpy((void *)&data->arene[4096 / data->nb_champ * (tmp->n_p - 1)], (void *)tmp->code, (size_t)tmp->size);
		tmp->adr = &data->arene[4096 / data->nb_champ * (tmp->n_p - 1)];
		tmp = tmp->next;
	}
}