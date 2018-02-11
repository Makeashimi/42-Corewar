/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:15:02 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/11 16:42:55 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_reg(t_instruction *instruction, char *str, int i)
{
	int number;

	if (str[0] != 'r')
		error("Syntax error with the register of the param, expected 'r'");
	number = ft_atoi(str + 1);
	ft_printf("number : %d\n", number);
	if (number == 0)
		error("Nothing or wrong thing after the 'r' register");
	if (number > REG_NUMBER || number < 0)
	{
		ft_printf(
		"Syntax error, expected a register bigger than -1 and lower than %d",
															REG_NUMBER + 1);
		error("");
	}
	instruction->param[i] = ft_strdup(ft_itoa(number));
	ft_printf("str apres : %s\n", instruction->param[i]);
}

void	check_dir(t_instruction *instruction, char *str, int i)
{
	(void)instruction, (void)str, (void)i;
	/*
	int		j;
	int		count;

	j = 1;
	count = 0;
	ft_printf("str %s\n", str);
	if (str[0] != DIRECT_CHAR)
	{
		ft_printf("Syntax error, expected %c to begin", DIRECT_CHAR);
		error("");
	}
	if (str[1] != LABEL_CHAR && ft_isdigit(str[1]) == 0)
	{
		ft_printf("Nothing or wrong thing after the %c", DIRECT_CHAR);
		error("");
	}
	if (ft_isdigit(str[1]) == 1)
	{
		while (str[j] != '\0' && ft_space(str[j]) == 0)
		{
			if (ft_isdigit(str[j]) == 0)
				error("Syntax error with the direct param");
			j++;
			count++;
		}
	}
	//else
		//check_label(str + j, count);
	ft_printf("count : %d\n", count);
	instruction->param[i] = ft_strdup(str + 1);
	ft_printf("str apres : %s\n", instruction->param[i]);
	*/
}
