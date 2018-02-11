/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:16:54 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/11 16:39:23 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_param(t_instruction *instruction, char *str)
{
	ft_printf("l'instruction : %s\nsur son lit de label : %s\n%d\n%d\n%d\n",
	instruction->name, instruction->label,
	g_op_tab[(int)instruction->index].arg[0],
	g_op_tab[(int)instruction->index].arg[1],
	g_op_tab[(int)instruction->index].arg[2]);

	//char				*name;
	int					i;

	i = 0;
	check_dir(instruction, str, i);
	//check_reg(instruction, str, i);
	//name = instruction->name;
	//while (i < g_op_tab[(int)instruction->index].nb_param)
	//{
		// if (g_op_tab[(int)instruction->index].arg[i] == T_REG)
		// {
		// 	//etre au bon endroit
		// 	check_reg(instruction, str, i);
		// }
		// else if (g_op_tab[(int)instruction->index].arg[i] == T_DIR)
		// 	check_dir(instruction, str, i);
		//i++;
	//}
	//enregistrer tout ca apres
	return (1);
}

static int	is_confurm_label(char c)
{
	int		i;

	i = 0;
	while (LABEL_CHARS[i] != '\0')
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

int			is_label(t_instruction *instruction, char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0' && str[i] != LABEL_CHAR)
	{
		if (is_confurm_label(str[i]) == 0)
			return (0);
		i++;
	}
	if (str[i] == '\0' || i < 1)
		return (0);
	if (!(instruction->label = (char*)malloc(sizeof(char) * (i + 1))))
		error("Malloc error");
	instruction->label = strcpy_until(instruction->label, str, ':');
	instruction->label[i] = '\0';
	return (1);
}

int			is_name_instru(t_instruction *instruction, char *str)
{
	int				len;
	int				i;

	len = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
	{
		i++;
		len++;
	}
	if (!(instruction->name = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		error("Malloc error");
	instruction->name = ft_strncpy(instruction->name, str, len);
	instruction->name[len] = '\0';
	if (instruction->name[len - 1] == LABEL_CHAR)
		return (0);
	i = 0;
	while (i < (NBR_INSTRUCTIONS - 1) &&
					ft_strcmp(instruction->name, g_op_tab[i].name) != 0)
		i++;
	if (i == (NBR_INSTRUCTIONS - 1))
		return (0);
	instruction->index = i;
	return (1);
}
