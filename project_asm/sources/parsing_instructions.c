/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/03/07 17:12:26 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm			*get_tmp(t_asm *tmp)
{
	int		i;

	i = 0;
	while (tmp->str[i] != '\0' && tmp->str[i] != LABEL_CHAR)
		i++;
	if (tmp->str[i] == LABEL_CHAR)
	{
		i++;
		while (tmp->str[i] != '\0' && ft_space(tmp->str[i]) == 1)
			i++;
		if (tmp->str[i] == '\0')
		{
			tmp = tmp->next;
			while (tmp != NULL && is_all_space(tmp->str) == 1)
				tmp = tmp->next;
		}
		return (tmp);
	}
	return (tmp);
}

static	int		count_label(t_instruction *instruction,
											t_asm *tmp, int i, int count)
{
	char	*str;

	while (ft_space(tmp->str[i]) == 1)
		i++;
	while (tmp != NULL && is_label(instruction, tmp->str + i, 0, 0) == 1)
	{
		count++;
		str = ft_strdup(instru(tmp->str));
		if (ft_strcmp(tmp->str, str) != 0)
		{
			ft_strdel(&str);
			return (count);
		}
		ft_strdel(&str);
		tmp = tmp->next;
		i = 0;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		if (tmp == NULL)
			return (count);
		while (ft_space(tmp->str[i]) == 1)
			i++;
	}
	return (count);
}

void			op(char *cpy, t_asm *tmp, t_instruction *ins, int i)
{
	if (is_name_instru(ins, tmp->str + i) == 0)
		error("Syntax error with the label or the instruction");
	cpy = tmp->str;
	tmp->str = ft_strdup(move_to_param(tmp->str + i));
	ft_strdel(&cpy);
	if (check_param(ins, tmp->str) == 0)
		error("Syntax error with the params of the instruction");
}

t_asm			*instru_next(t_asm *tmp, t_instruction *ins, int i, int o)
{
	char	*cpy;

	while (tmp != NULL && is_label(ins, tmp->str + i, o, 1) == 1)
	{
		i = 0;
		cpy = tmp->str;
		tmp->str = ft_strdup(instru(tmp->str + i));
		if (ft_strcmp(cpy, tmp->str) != 0)
		{
			ft_strdel(&cpy);
			break ;
		}
		ft_strdel(&cpy);
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		while (ft_space(tmp->str[i]) == 1)
			i++;
		o++;
	}
	op(cpy, tmp, ins, i);
	return (tmp);
}

t_asm			*parse_instructions(t_instruction *instruction,
														t_asm *tmp, int i)
{
	int		count;

	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		error("Nothing found after name/comment");
	while (ft_space(tmp->str[i]) == 1)
		i++;
	count = count_label(instruction, tmp, 0, 0);
	if (!(instruction->label = (char**)malloc(sizeof(char*) * (count + 1))))
		error("Malloc error");
	instruction->label[count] = NULL;
	tmp = instru_next(tmp, instruction, i, 0);
	return (tmp);
}
