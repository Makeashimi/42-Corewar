/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:30:18 by varichar          #+#    #+#             */
/*   Updated: 2018/03/12 17:33:43 by varichar         ###   ########.fr       */
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
		ins->size += (ins->name) ? 1 : 0;
		if (ins->name)
			ins->size += (g_op_tab[(int)ins->index].ocp ? 1 : 0);
		i = 0;
		while (ins->param[i] && i < 3)
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
	if (ins->type[i] == 1)
		return (1);
	else
		return ((ins->type[i] == 2 && !g_op_tab[(int)(ins->index)].short_dir) ?\
			4 : 2);
}

int		find_label(char *label, char **llabel)
{
	if (label && *llabel)
	{
		while (*llabel)
		{
			if (ft_strcmp(*llabel, label) == 0)
				return (1);
			llabel++;
		}
	}
	return (0);
}

t_asm	*create_str(char *str)
{
	t_asm	*tmp;

	if (!(tmp = (t_asm*)malloc(sizeof(t_asm))))
		error("Malloc error");
	ft_memset(tmp, 0, sizeof(t_asm));
	if (!(tmp->str = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		error("Malloc error");
	tmp->str = ft_strcpy(tmp->str, str);
	return (tmp);
}

t_asm	*link_str(t_asm *l_asm, char *str)
{
	t_asm	*tmp;

	tmp = l_asm;
	if (l_asm == NULL)
	{
		l_asm = create_str(str);
		return (l_asm);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_str(str);
	return (l_asm);
}
