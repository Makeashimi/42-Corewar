/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:11:24 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 12:41:45 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static	int	ft_verif(int i, char *big, char *little)
{
	int j;

	j = 0;
	while (little[j] != '\0')
	{
		if (big[i] != little[j] || big[i] == '\0')
			return (0);
		i++;
		j++;
	}
	return (1);
}

char		*ft_strstr(const char *big, const char *little)
{
	int i;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		if (little[0] == big[i])
		{
			if (ft_verif(i, (char*)big, (char*)little))
				return ((char*)big + i);
		}
		i++;
	}
	return (0);
}
