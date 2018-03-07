/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ocp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:03:38 by thbricqu          #+#    #+#             */
/*   Updated: 2018/03/05 14:34:28 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_bits(unsigned char octet, char tab[])
{
	int	oct;
	int	div;
	int	i;

	i = 0;
	tab[8] = '\0';
	div = 128;
	oct = octet;
	while (div != 0)
	{
		if (div <= oct)
		{
			tab[i++] = '1';
			oct = oct % div;
		}
		else
			tab[i++] = '0';
		div = div / 2;
	}
}

static int		nb_octet(int i)
{
	if (i == 1 || i == 2
			|| i == 3 || i == 4
			|| i == 5 || i == 6
			|| i == 7 || i == 8
			|| i == 13 || i == 16
			|| i > 16)
		return (0);
	return (1);
}

static void		type_param(char tab[], t_cor *proc, t_data *data)
{
	int i;
	int c;

	c = 1;
	i = 0;
	proc->param[0] = data->arene[(proc->ptr + 1) % MEM_SIZE];
	while (c < 4)
	{
		if (tab[i] == '1' && tab[i + 1] == '1')
			proc->param[c] = 2;
		else if ((tab[i] == '1' && tab[i + 1] == '0') && proc->param[4] == 0)
			proc->param[c] = 4;
		else if ((tab[i] == '1' && tab[i + 1] == '0') && proc->param[4] == 1)
			proc->param[c] = 3;
		else if (tab[i] == '0' && tab[i + 1] == '1')
			proc->param[c] = 1;
		else if (tab[i] == '0' && tab[i + 1] == '0')
			proc->param[c] = 0;
		i = i + 2;
		c++;
	}
}

void			cal_ocp(t_cor *proc, t_data *data)
{
	int		i;
	char	tab[9];

	i = proc->inst;
	proc->param[4] = nb_octet(i);
	i = (proc->ptr + 1) % MEM_SIZE;
	print_bits(data->arene[i], tab);
	type_param(tab, proc, data);
}

int				rev_end(int val, char size)
{
	if (size == 1)
		return (val);
	else if (size == 2)
		return (val >> 8 | val << 8);
	else if (size == 4)
		return (((val >> 24) & 0xff) |
				((val << 8) & 0xff0000) |
				((val >> 8) & 0xff00) |
				((val << 24) & 0xff000000));
	else
		return (0);
}
