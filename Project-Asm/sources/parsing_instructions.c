/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/28 21:31:04 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** ligne du label + instruction -> tmp
** ligne de l'instruction -> tmp
** ligne du label -> next
*/

char	*move_to_param(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && ft_space(str[i]) == 0)
		i++;
	if (str[i] == 0)
		error("No parameters");
	while (str[i] != '\0' && ft_space(str[i]) == 1)
		i++;
	if (str[i] == 0)
		error("No parameters");
	return (str + i);
}

t_asm	*get_tmp(t_asm *tmp)
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
		tmp = tmp->next;
		i = 0;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		if (tmp == NULL)
			return (count);
		while (ft_space(tmp->str[i]) == 1)
			i++;
		count++;
	}
	return (count);
}

t_asm	*parse_instructions(t_instruction *instruction, t_asm *tmp,
															int i)
{
	int		count;
	int 	o;

	o = 0;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		error("Nothing found after name/comment");
	while (ft_space(tmp->str[i]) == 1)
		i++;
	count = count_label(instruction, tmp);
	//ft_printf("count : %d\n", count);
	if (!(instruction->label = (char**)malloc(sizeof(char*) * (count + 1))))
		error("Malloc error");
	instruction->label[count] = NULL;
	while (tmp != NULL && is_label(instruction, tmp->str + i, o, 1) == 1)
	{
		tmp = tmp->next;
		i = 0;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		while (ft_space(tmp->str[i]) == 1)
			i++;
		o++;
	}
	if (is_name_instru(instruction, tmp->str + i) == 0)
		error("Syntax error with the label or the instruction");
	tmp->str = move_to_param(tmp->str + i);
	if (check_param(instruction, tmp->str) == 0)
		error("Syntax error with the params of the instruction");
	ft_printf("ICI : %s\n", tmp->str);
	return (tmp);
}
