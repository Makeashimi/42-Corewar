/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/15 15:58:46 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

char	*move_to_instru(t_asm *tmp)
{
	int		i;

	i = 0;
	if (ft_space(tmp->str[i]) == 1)
	{
		while (ft_space(tmp->str[i]) == 0)
			i++;
	}
	while (tmp->str[i] != LABEL_CHAR)
		i++;
	i++;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	if (tmp->str[i] == '\0' || tmp->str[i] == COMMENT_CHAR)
	{
		i = 0;
		tmp = tmp->next;
	}
	while (tmp != NULL && is_all_space(tmp->str) == 1)
	{
		i = 0;
		tmp = tmp->next;
	}
	//ft_printf("%s\n", tmp->str);
	if (tmp == NULL)
		error("No instructions found");
	while (ft_space(tmp->str[i]) == 1)
		i++;
	return (tmp->str + i);
}

//D'un coté, j'ai le cas où "l2 : sti", de l'autre "l2 : \n sti".
//Si l'instruction est sur la meme ligne, je retourne juste la ligne.
//Si l'instruction est pas sur la bonne ligne, y aller.
//Dans les 2 cas, retourner la ligne de l'instruction.

t_asm	*get_tmp(t_asm *tmp)
{
	int 	j;
	int		i;

	i = 0;
	j = 0;
	//ft_printf("LE DEPART : %s\n", tmp->str);
	while (tmp->str[i] != '\0' && tmp->str[i] != LABEL_CHAR)
		i++;
	//ligne du label + instruction -> tmp
	//ligne de l'instruction -> tmp
	//ligne du label -> next
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

t_asm	*parse_instructions(t_instruction *instruction, t_asm *tmp)
{
	char 	*ins;
	int		ret;
	int		i;
	int		o;

	ret = 0;
	o = 0;
	i = 0;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		error("Nothing found after name/comment");
	while (ft_space(tmp->str[i]) == 1)
		i++;
	ret = is_label(instruction, tmp->str + i);
	ins = tmp->str + i;
	if (ret == 1)
	{
		ins = move_to_instru(tmp);
		i = 0;
	}
	if (is_name_instru(instruction, ins) == 0)
		error("Syntax error with the label or the instruction");
	ins = move_to_param(ins);
	if (check_param(instruction, ins) == 0)
		error("Syntax error with the params of the instruction");
	tmp = get_tmp(tmp);
	//ft_printf("L'ARRIVÉE : %s\n", tmp->str);
	return (tmp);
}
