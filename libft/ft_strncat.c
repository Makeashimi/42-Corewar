/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:13:10 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:01:39 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = len1 + len2;
	if (n <= len2)
	{
		ft_memcpy(s1 + len1, s2, n);
		s1[n + len1] = '\0';
	}
	if (n > len2)
	{
		ft_memcpy(s1 + len1, s2, len2);
		s1[i] = '\0';
	}
	return (s1);
}
