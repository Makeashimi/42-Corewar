/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/08 22:43:30 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** T_REG -> 1
** T_DIR -> 2
** T_DIR ou T_REG -> 3
** (NEVER APPEARED)T_IND -> 4
** T_REG ou T_IND -> 5
** T_DIR ou T_IND -> 6
** T_DIR ou T_REG ou T_IND -> 7
** ------------------------
** if (g_op_tab[instruction->index].arg[0] == 1)
**	 T_REG needed
** else if (g_op_tab[instruction->index].arg[0] == 2)
** 	T_DIR needed
** else if (g_op_tab[instruction->index].arg[0] == 3)
** 	T_DIR OU T_REG needed
** else if (g_op_tab[instruction->index].arg[0] == 5)
** 	T_REG ou T_IND needed
** else if (g_op_tab[instruction->index].arg[0] == 6)
** 	T_DIR ou T_IND needed
** else if (g_op_tab[instruction->index].arg[0] == 7)
**	 T_DIR OU T_REG OU T_IND needed
*/

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

int		check_name_instru(t_instruction **instruction, char *str)
{
	t_instruction	*tmp;
	int				len;
	int				i;

	len = 0;
	i = 0;
	//ft_printf("str avant : %s\n", str);
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
	{
		i++;
		len++;
	}
	//ft_printf("len : %d et str : %s\n", len, str);
	tmp = link_instruction(instruction, str, len);
	if ((*instruction)->name[len - 1] == LABEL_CHAR)
		return (0);
	i = 0;
	while (i < (NBR_INSTRUCTIONS - 1) && ft_strcmp((*instruction)->name, g_op_tab[i].name) != 0)
		i++;
	//ft_printf("i : %d\n", i);
	if (i == (NBR_INSTRUCTIONS - 1))
		return (0);
	tmp->index = i;
	//ft_printf("instruction->name : %s et instruction->index : %d\n", instruction->name, instruction->index);
	return (1);
}

int		check_param(t_instruction *instruction, char *tmp)
{
	char 	*name;
	int		i;

	i = 0;
	//ft_printf("salut ? \n");
	name = get_last_instru(instruction);
	//ft_printf("salut ? \n");
	//ft_printf("instruction->name : %s\n", name);
	ft_printf("%s :\n%d\n%d\n%d\n", name, g_op_tab[instruction->index].arg[0], g_op_tab[instruction->index].arg[1], g_op_tab[instruction->index].arg[2]);
	while (i < g_op_tab[instruction->index].nb_param)
	{
		if (g_op_tab[instruction->index].arg[i] == T_REG)
		{
			//etre au bon endroit

			check_reg(tmp);
		}
		else if (g_op_tab[instruction->index].arg[i] == T_DIR)
			check_dir(tmp);
		i++;
	}
	//enregistrer tout ca apres
	return (1);
}

void	parse_instructions(t_asm *l_asm, t_instruction *instruction, t_asm *tmp)
{
	int		i;
	int		o;

	o = 0;
	i = 0;
	(void)l_asm;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	if (is_label(tmp->str + i) == 0 && check_name_instru(&instruction, tmp->str + i) == 0)
		error("Syntax error with the label or the instruction");
	//ft_printf("str       : %s\n", tmp->str + i);
	while (tmp->str[i] != LABEL_CHAR && ft_space(tmp->str[i]) != 1)
		i++;
	//ft_printf("str avant : %s\n", tmp->str + i);
	if (tmp->str[i] == LABEL_CHAR)
	{
		i++;
		while (ft_space(tmp->str[i]) == 1)
			i++;
		if (tmp->str[i] == '\0')
		{
			i = 0;
			tmp = tmp->next;
		}
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		while (ft_space(tmp->str[i]) == 1)
			i++;
		//ft_printf("str dans le label : %s\n", tmp->str + i);
		if (check_name_instru(&instruction, tmp->str + i) == 0)
			error("Syntax error with the instruction");
		while (ft_space(tmp->str[i]) == 0)
			i++;
	}
	//ft_printf("str avant : %s\n", tmp->str + i);
	while (ft_space(tmp->str[i]) == 1)
		i++;
	ft_printf("str : %s\n", tmp->str + i);
	if (tmp->str[i] == '\0')
		error("Syntax error with the instruction");
	if (check_param(instruction, tmp->str + i) == 0)
		error("Bloublou");
}
