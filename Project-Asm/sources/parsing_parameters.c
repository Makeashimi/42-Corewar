/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:22:09 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/14 16:25:48 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*move_str(t_instruction *instruction, char *str, int i, int j)
{
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
		str = move_str(instruction, str, i, 0);
		i++;
	}
	return (1);
}
