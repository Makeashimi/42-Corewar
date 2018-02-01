/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/01 21:30:08 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_confurm(char c)
{
	int		i;

	i = 0;
	//ft_printf("c : %c\n", c);
	while (LABEL_CHARS[i] != '\0')
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_label(char *str)
{
	int		i;

	i = 0;
	//ft_printf("str avant : %s\n", str);
	while (str[i] != '\0' && str[i] != LABEL_CHAR)
	{
		//ft_printf("str avant : %s\n", str + i);
		if (is_confurm(str[i]) == 0)
		{
			//ft_printf("i : %c\n", str[i]);
			return (0);
		}
		i++;
	}
	if (str[i] == '\0' || i < 1)
		return (0);
	return (1);
}

int		is_instruction(char *str)
{
	char 	*cpy;
	int 	len;
	int		i;

	len = 0;
	i = 0;
	//ft_printf("str avant : %s\n", str);
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
	{
		i++;
		len++;
	}
	//ft_printf("len : %d\n", len);
	if (!(cpy = (char*)malloc(sizeof(char) * (len + 1))))
		error("Malloc error");
	cpy[len] = '\0';
	cpy = ft_strncpy(cpy, str, len);
	//ft_printf("cpy : %s\n", cpy);
	if (cpy[len - 1] == LABEL_CHAR)
		return (0);
	i = 0;
	while (i < (NBR_INSTRUCTIONS - 1) && ft_strcmp(cpy, g_op_tab[i].name) != 0)
		i++;
	//ft_printf("i : %d\n", i);
	return (i == (NBR_INSTRUCTIONS - 1) ? 0 : 1);
}

void	parse_instructions(t_asm *tmp)
{
	int		i;
	int		o;

	o = 0;
	i = 0;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	//ft_printf("i : %c\n", tmp->str[i]);
	if (is_label(tmp->str + i) == 0 && is_instruction(tmp->str + i) == 0)
		error("Syntax error with the label or the instruction");
}
