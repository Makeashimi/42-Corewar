/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/03/02 19:11:53 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm			*get_tmp(t_asm *tmp)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
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

static	int		count_label(t_instruction *instruction, t_asm *tmp)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	while (tmp != NULL && is_label(instruction, tmp->str + i, 0, 0) == 1)
	{
		count++;
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

char			*instru(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == LABEL_CHAR)
		{
			i++;
			while (ft_space(str[i]) == 1)
				i++;
			if (str[i] != '\0' && str[i] != COMMENT_CHAR)
				return (str + i);
		}
		i++;
	}
	return (NULL);
}

t_asm			*instru_next(t_asm *tmp, t_instruction *ins, int i, int o)
{
	while (tmp != NULL && is_label(ins, tmp->str + i, o, 1) == 1)
	{
		i = 0;
		if ((tmp->str = instru(tmp->str + i)) != NULL)
			break ;
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		while (ft_space(tmp->str[i]) == 1)
			i++;
		o++;
	}
	if (is_name_instru(ins, tmp->str + i) == 0)
		error("Syntax error with the label or the instruction");
	tmp->str = move_to_param(tmp->str + i);
	if (check_param(ins, tmp->str) == 0)
		error("Syntax error with the params of the instruction");
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
	count = count_label(instruction, tmp);
	if (!(instruction->label = (char**)malloc(sizeof(char*) * (count + 1))))
		error("Malloc error");
	instruction->label[count] = NULL;
	tmp = instru_next(tmp, instruction, i, 0);
	return (tmp);
}
