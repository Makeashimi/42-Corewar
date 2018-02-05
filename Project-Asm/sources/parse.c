/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/03 22:09:44 by jcharloi         ###   ########.fr       */
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

int		is_instruction(t_asm *l_asm, char *str)
{
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
	if (!(l_asm->name_instruction = (char*)malloc(sizeof(char) * (len + 1))))
		error("Malloc error");
	l_asm->name_instruction[len] = '\0';
	l_asm->name_instruction = ft_strncpy(l_asm->name_instruction, str, len);
	ft_printf("l_asm->name_instruction : %s\n", l_asm->name_instruction);
	if (l_asm->name_instruction[len - 1] == LABEL_CHAR)
		return (0);
	i = 0;
	while (i < (NBR_INSTRUCTIONS - 1) && ft_strcmp(l_asm->name_instruction, g_op_tab[i].name) != 0)
		i++;
	//ft_printf("i : %d\n", i);
	if (i == (NBR_INSTRUCTIONS - 1))
		return (0);
	return (1);
}

int 	check_param(char *name, char *tmp)
{
	int 	i;
	int		virgule;

	(void)name;
	i = 0;
	virgule = 0;
	ft_printf("str : %s\n", tmp);
	while (tmp[i] != '\0' && tmp[i] != COMMENT_CHAR)
	{
		if (tmp[i] == SEPARATOR_CHAR)
			virgule++;
		i++;
	}
	ft_printf("virgule : %d\n", virgule);
	//VERIFIER LA VIRGULE AU BON ENDROIT APRES AVOIR VERIFIÉ QU'ELLE EST APPARU ENTRE CHAQUE INSTRU
	i = 0;

	return (1);
}

void	parse_instructions(t_asm *l_asm, t_asm *tmp)
{
	int		i;
	int o;

	o = 0;
	i = 0;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	if (is_label(tmp->str + i) == 0 && is_instruction(l_asm, tmp->str + i) == 0)
		error("Syntax error with the label or the instruction");
	//ft_printf("str       : %s\n", tmp->str + i);
	while (tmp->str[i] != ':' && ft_space(tmp->str[i]) != 1)
		i++;
	ft_printf("str avant : %s\n", tmp->str + i);
	if (tmp->str[i] == ':')
	{
		i++;
		//IL PEUT Y AVOIR DES ESPACES BLANCS AVANT L"INSTRUCTIOn
		ft_printf("str apres : %s\n", tmp->str + i);
		if (is_instruction(l_asm, tmp->str + i) == 0)
			error("Syntax error with the instruction");
	}
	while (ft_space(tmp->str[i]) == 1)
		i++;
	//ft_printf("str : %s\n", tmp->str + i);
	//ft_printf("l_asm->name_instruction");
	if (check_param(l_asm->name_instruction, tmp->str + i) == 0)
		error("Bloublou");
}
