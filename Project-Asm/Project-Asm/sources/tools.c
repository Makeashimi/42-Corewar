/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:48:14 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/25 19:07:45 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int		is_all_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			while (str[i] != '\0' && ft_iswhitespace(str[i]) == 0)
				i++;
		}
		if (str[i] == '\0')
			break ;
		//ft_printf("str : %s\n", str + i);
		if (ft_iswhitespace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
