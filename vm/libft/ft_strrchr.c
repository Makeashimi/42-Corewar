/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:03:59 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 12:47:50 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr_s;
	char	c2;
	int		i;

	ptr_s = (char*)s;
	c2 = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (ptr_s[i] == c2)
			return (&ptr_s[i]);
		i--;
	}
	return (NULL);
}
