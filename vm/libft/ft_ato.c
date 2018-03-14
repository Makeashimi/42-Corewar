/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:24:33 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/30 13:36:11 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		fraiche;
	int		i;
	int		isnegative;

	fraiche = 0;
	i = 0;
	isnegative = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		i++;
		isnegative = 1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (ft_isdigit(str[i])))
	{
		fraiche = (fraiche * 10) + (str[i] - 48);
		i++;
	}
	if (isnegative == 1)
		return (-fraiche);
	else
		return (fraiche);
}

long	ft_atol(const char *str)
{
	int		i;
	long	nb;
	int		negative;

	i = 0;
	nb = 0;
	negative = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (negative)
		return (-nb);
	return (nb);
}
