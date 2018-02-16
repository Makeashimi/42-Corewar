/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ocp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:03:38 by thbricqu          #+#    #+#             */
/*   Updated: 2018/02/16 17:06:10 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	nb_octet(t_cor *p, t_data *d, int i)
{
	int ret;
	int c;

	ret = 0;
	c = 1;
	if (i > 3 || i < 1)
		return (g_op_tab[(d->arene[p->ptr]) - 1].short_dir);
	ret += g_op_tab[(p->ptr) - 1].ocp;
	while (c <= i)
	{
		if (p->param[c] == T_REG)
			ret += 1;
		else if (p->param[c] == T_DIR && nb_octet(p, d, 0))
			ret += 4;
		else
			ret += 2;
	}
	return (ret);
}

static int	check_ocp(t_cor *p, t_data *d)
{
	int i;

	i = 1;
	while (i < 4)
	{
		if ((p->param[i] != (p->param[i] & g_op_tab[(d->arene[p->ptr]) -\
					1].arg[i])))
			return (nb_octet(p, d, i));
	}
	return (0);
}

static void	type_param(char tab[], t_cor *proc, t_data *data)
{
	int i;

	i = 0;

	while(i < 3)
	{
		if (tab[i] == REG_CODE)
			proc->param[i + 1] = T_REG;
		else if (tab[i] == DIR_CODE)
			proc->param[i + 1] = T_DIR;
		else if (tab[i] == IND_CODE)
			proc->param[i + 1] = T_IND;
		else 
			proc->param[i + 1]= 0;
		i++;
	}
}

int		calc_ocp(t_cor *proc, t_data *data)
{
	int ret;
	char tab[3];

	ret = 0;
	proc->pc = proc->ptr + 1;
	proc->param[4] = nb_octet(proc, data, 4);
	if (g_op_tab[(proc->ptr) - 1].ocp)
		proc->param[0] = proc->pc;
	else
		proc->param[0] = 0;
	tab[0] = (proc->param[0] & 192) >> 6;
	tab[1] = (proc->param[0] & 48) >> 4;
	tab[2] = (proc->param[0] & 12) >> 2;
	type_param(tab, proc, data);
	return (ret);
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
