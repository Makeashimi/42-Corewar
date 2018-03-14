/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:00:16 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/09 14:44:26 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_verif(size_t len, int i, char *big, char *little)
{
	int j;

	j = 0;
	while (little[j] != '\0')
	{
		if (big[i] != little[j] || big[i] == '\0' || len == 0)
			return (0);
		i++;
		j++;
		len--;
	}
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int				i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && len)
	{
		if (little[j] == big[i])
		{
			if (ft_verif(len, i, (char*)big, (char*)little))
				return ((char*)big + i);
		}
		len--;
		i++;
	}
	return (0);
}
