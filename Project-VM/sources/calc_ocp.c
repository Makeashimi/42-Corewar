/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ocp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:03:38 by thbricqu          #+#    #+#             */
/*   Updated: 2018/02/13 15:03:41 by thbricqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void        print_bits(unsigned char octet, char tab[])
{
    int        oct;
    int        div;
    int        i;

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

static int	nb_octet(t_cor *p, t_data *d)
{
	if(d->arene[p->ptr] == 0x01 || d->arene[p->ptr] == 0x02
		|| d->arene[p->ptr] == 0x03 || d->arene[p->ptr] == 0x04
		|| d->arene[p->ptr] == 0x05 || d->arene[p->ptr] == 0x06
		|| d->arene[p->ptr] == 0x07 || d->arene[p->ptr] == 0x08
		|| d->arene[p->ptr] == 0x0d || d->arene[p->ptr] == 0x10)
		return (0);
	return (1);
}

static void	type_param(char tab[], t_cor *proc, t_data *data)
{
	int i;
	int c;

	c = 1;
	i = 0;

	proc->param[0] = data->arene[proc->ptr + 1];
	while(c < 5)
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

void	cal_ocp(t_cor *proc, t_data *data)
{
	int i;
	char tab[9];

	i = proc->ptr;
	proc->param[4] = nb_octet(proc, data);
	i++;
	print_bits(data->arene[i], tab);
	type_param(tab, proc, data);

}

int		rev_end(int val, char size)
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
	return (0);
}
