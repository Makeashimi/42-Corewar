/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:34:02 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:23:45 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	c2;

	ptr_s = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (n > 0)
	{
		if (c2 == *ptr_s)
			return (ptr_s);
		ptr_s++;
		n--;
	}
	return (NULL);
}
