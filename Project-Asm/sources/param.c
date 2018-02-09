/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:15:02 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/09 21:27:35 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_reg(char *str)
{
	int number;

	if (str[0] != 'r')
		error("Syntax error with the register of the param, expected 'r'");
	number = ft_atoi(str + 1);
	ft_printf("%d\n", number);
	if (number == 0)
		error("Nothing or wrong thing after the 'r' register");
	if (number > REG_NUMBER || number < 0)
	{
		ft_printf(
		"Syntax error, expected a register bigger than -1 and lower than %d",
															REG_NUMBER + 1);
		error("");
	}
}

void	check_dir(char *str)
{
	int		i;

	i = 1;
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
		while (str[i] != '\0' && ft_space(str[i]) == 0)
		{
			if (ft_isdigit(str[i]) == 0)
				error("Syntax error with the direct param");
			i++;
		}
	}
	//else
		//check_label();
}
