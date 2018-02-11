/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:16:54 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/11 20:26:26 by jcharloi         ###   ########.fr       */
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
*/

char		*move_str(char *str, int virgule)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != SEPARATOR_CHAR)
		i++;
	if (str[i] == '\0' && virgule > 3)
		error("Syntax error with the parameters");
	i++;
	return (str + i);
}

int			check_param(t_instruction *instruction, char *str)
{
	// ft_printf("l'instruction : %s\nsur son lit de label : %s\n%d\n%d\n%d\n",
	// instruction->name, instruction->label,
	// g_op_tab[(int)instruction->index].arg[0],
	// g_op_tab[(int)instruction->index].arg[1],
	// g_op_tab[(int)instruction->index].arg[2]);
	int		i;
	//int		virgule;

	i = 0;
	//virgule = 0;
	while (i < g_op_tab[(int)instruction->index].nb_param)
	{
		if (g_op_tab[(int)instruction->index].arg[i] == T_REG)
		{

			if (check_reg(instruction, str, i) == 0)
			{
				ft_printf("Invalid parameter for %s instruction", instruction->name);
				error("");
			}
		}
		else if (g_op_tab[(int)instruction->index].arg[i] == T_DIR)
		{
			
			if (check_dir(instruction, str, i) == 0)
			{
				ft_printf("Invalid parameter for %s instruction", instruction->name);
				error("");
			}
		}
		else if (g_op_tab[(int)instruction->index].arg[i] == T_IND)
		{
			
			if (check_ind(instruction, str, i) == 0)
			{
				ft_printf("Invalid parameter for %s instruction", instruction->name);
				error("");
			}
		}
		else if (g_op_tab[(int)instruction->index].arg[i] == (T_REG + T_DIR))
		{
			//T_DIR ou T_REG needed
			if (check_dir(instruction, str, i) == 0 && check_reg(instruction, str, i) == 0)
			{
				ft_printf("Invalid parameter for %s instruction", instruction->name);
				error("");
			}
		}
		else if (g_op_tab[(int)instruction->index].arg[i] == (T_REG + T_IND))
		{
			//T_REG ou T_IND needed
			if (check_reg(instruction, str, i) == 0 && check_ind(instruction, str, i) == 0)
			{
				ft_printf("Invalid parameter for %s instruction", instruction->name);
				error("");
			}
		}
		else if (g_op_tab[(int)instruction->index].arg[i] == (T_DIR + T_IND))
		{
			//T_DIR ou T_IND needed
			if (check_dir(instruction, str, i) == 0 && check_ind(instruction, str, i) == 0)
			{
				ft_printf("Invalid parameter for %s instruction", instruction->name);
				error("");
			}
		}
		else if (g_op_tab[(int)instruction->index].arg[i] == (T_REG + T_DIR + T_IND))
		{
			//T_DIR OU T_REG OU T_IND needed
			if (check_reg(instruction, str, i) == 0 && check_dir(instruction, str, i) == 0 && check_ind(instruction, str, i) == 0)
			{
				ft_printf("Invalid parameter for %s instruction", instruction->name);
				error("");
			}
		}
		str = move_str(str, 0);//mettre str au bon endroit
		//PARSING DE LA VIRGULE ICI
		i++;
	}
	//ft_printf("virgule : %d et i : %d\n", virgule, i);
	// if (virgule > i)
	// {
	// 	ft_printf("Too much %c", SEPARATOR_CHAR);
	// 	error("");
	// }
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
