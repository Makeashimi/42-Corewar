/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsrchi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:41:33 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/09 15:47:23 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsrchi(const char *s, int c)
{
	unsigned char	*ptr_s;
	int				i;

	ptr_s = (unsigned char*)s;
	i = 0;
	while (ptr_s[i] != '\0')
	{
		if (ptr_s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		str_nbr_i(char *str, char c)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nbr++;
		i++;
	}
	return (nbr);
}
