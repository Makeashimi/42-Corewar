/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:16:54 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/14 15:13:41 by jcharloi         ###   ########.fr       */
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
** 	 T_DIR needed
** else if (g_op_tab[instruction->index].arg[0] == 3)
** 	 T_DIR OU T_REG needed
** else if (g_op_tab[instruction->index].arg[0] == 5)
** 	 T_REG ou T_IND needed
** else if (g_op_tab[instruction->index].arg[0] == 6)
** 	 T_DIR ou T_IND needed
** else if (g_op_tab[instruction->index].arg[0] == 7)
**	 T_DIR OU T_REG OU T_IND needed
** instruction->param[1] = 1;
** instruction->param[2] = 0 ou :live;
** instruction->param[3] = 0 ou :live;
** Enregistrer et comparer tous les parametres, les registres
** les directs, les indirects
** Verifier la virgule !
*/

char		*move_str(t_instruction *instruction, char *str, int i)
{
	int		j;

	j = 0;
	if ((i + 1) == g_op_tab[(int)instruction->index].nb_param)
	{
		while (str[j] != '\0' && ft_space(str[j]) == 0)
		{
			if (str[j] == SEPARATOR_CHAR)
				error("Characters after parameters");
			j++;
		}
		while (str[j] != '\0')
		{
			if (str[j] == COMMENT_CHAR)
				return (NULL);
			if (ft_space(str[j]) == 0)
				error("Characters after parameters");
			j++;
		}
	}
	while (str[j] != '\0' && str[j] != SEPARATOR_CHAR)
		j++;
	j++;
	while (ft_space(str[j]) == 1)
		j++;
	return (str + j);
}

void		check_param2(t_instruction *ins, char *str, int i)
{
	if (g_op_tab[(int)ins->index].arg[i] == T_IND)
	{
		if (check_ind(ins, str, i) == 0)
		{
			ft_printf("Invalid parameter for %s instruction", ins->name);
			error("");
		}
	}
	else if (g_op_tab[(int)ins->index].arg[i] == (T_REG + T_DIR))
	{
		if (check_dir(ins, str, i) == 0 && check_reg(ins, str, i) == 0)
		{
			ft_printf("Invalid parameter for %s instruction", ins->name);
			error("");
		}
	}
	else if (g_op_tab[(int)ins->index].arg[i] == (T_REG + T_IND))
	{
		if (check_reg(ins, str, i) == 0 && check_ind(ins, str, i) == 0)
		{
			ft_printf("Invalid parameter for %s instruction", ins->name);
			error("");
		}
	}
}

void		check_param3(t_instruction *ins, char *str, int i)
{
	if (g_op_tab[(int)ins->index].arg[i] == (T_DIR + T_IND))
	{
		if (check_dir(ins, str, i) == 0 &&
											check_ind(ins, str, i) == 0)
		{
			ft_printf("Invalid parameter for %s instruction", ins->name);
			error("");
		}
	}
	else if (g_op_tab[(int)ins->index].arg[i] == (T_REG + T_DIR + T_IND))
	{
		if (check_reg(ins, str, i) == 0 && check_dir(ins, str, i) == 0
										&& check_ind(ins, str, i) == 0)
		{
			ft_printf("Invalid parameter for %s instruction", ins->name);
			error("");
		}
	}
}

void		check_param1(t_instruction *ins, char *str, int i)
{
	if (g_op_tab[(int)ins->index].arg[i] == T_REG)
	{
		if (check_reg(ins, str, i) == 0)
		{
			ft_printf("Invalid parameter for %s instruction", ins->name);
			error("");
		}
	}
	else if (g_op_tab[(int)ins->index].arg[i] == T_DIR)
	{
		if (check_dir(ins, str, i) == 0)
		{
			ft_printf("Invalid parameter for %s instruction", ins->name);
			error("");
		}
	}
}

int			check_param(t_instruction *instruction, char *str)
{
	int		i;

	i = 0;
	while (i < g_op_tab[(int)instruction->index].nb_param)
	{
		check_param1(instruction, str, i);
		check_param2(instruction, str, i);
		check_param3(instruction, str, i);
		str = move_str(instruction, str, i);
		i++;
	}
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
	int			i;

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
	int			len;
	int			i;

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
