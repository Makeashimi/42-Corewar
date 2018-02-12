/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:15:02 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/12 18:28:03 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_reg(t_instruction *instruction, char *str, int i)
{
	int number;

	if (str[0] != 'r')
		return (0);
	number = ft_atoi(str + 1);
	if (number == 0)
		return (0);
	if (number > REG_NUMBER || number < 0)
		return (0);
	instruction->param[i] = ft_strdup(ft_itoa(number));
	//ft_printf("REGISTRE : instruction->param[i] : %s\n", instruction->param[i]);
	instruction->type[i] = REG_CODE;
	return (1);
}

int		check_dir_ind(char *str)
{
	int		i;
	int 	count;

	i = 0;
	count = 0;
	if (str[i] != LABEL_CHAR && ft_isdigit(str[i]) == 0)
		return (0);
	if (ft_isdigit(str[i]) == 1)
	{
		while (str[i] != '\0' && ft_space(str[i]) == 0 && str[i] != SEPARATOR_CHAR)
		{
			if (ft_isdigit(str[i]) == 0)
				return (0);
			i++;
			count++;
		}
	}
	else
	{
		count = 5;
		//count = check_label(str + j, count);
	}
	return (count);
}

int		check_dir(t_instruction *instruction, char *str, int i)
{
	int		count;

	count = 0;
	if (str[0] != DIRECT_CHAR)
		return (0);
	count = check_dir_ind(str + 1);
	if (count == 0)
		return (0);
	//ft_printf("count : %d\n", count);
	if (!(instruction->param[i] = (char *)malloc(sizeof(char) * (count + 1))))
		error("Malloc error");
	instruction->param[i] = ft_strncpy(instruction->param[i], str + 1, count);
	instruction->param[i][count] = '\0';
	//ft_printf("DIRECT : instruction->param[i] : %s\n", instruction->param[i]);
	instruction->type[i] = DIR_CODE;
	return (1);
}

int		check_ind(t_instruction *instruction, char *str, int i)
{
	int		count;

	count = check_dir_ind(str);
	if (count == 0)
		return (0);
	//ft_printf("count : %d\n", count);
	if (!(instruction->param[i] = (char *)malloc(sizeof(char) * (count + 1))))
		error("Malloc error");
	instruction->param[i] = ft_strncpy(instruction->param[i], str, count);
	instruction->param[i][count] = '\0';
	//ft_printf("INDIRECT : instruction->param[i] : %s\n", instruction->param[i]);
	instruction->type[i] = IND_CODE;
	return (1);
}
