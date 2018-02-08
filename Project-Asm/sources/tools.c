/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:48:14 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/03 19:57:00 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

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
		if (str[i] == COMMENT_CHAR)
			return (1);
		//ft_printf("str : %s\n", str + i);
		if (ft_space(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
