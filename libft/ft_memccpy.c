/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:09:18 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:23:30 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;
	unsigned char	c_;

	ptr_src = (unsigned char*)src;
	ptr_dst = (unsigned char*)dst;
	c_ = (unsigned char)c;
	while (n)
	{
		*ptr_dst = *ptr_src;
		if (c_ == *ptr_src)
		{
			*ptr_dst = *ptr_src;
			return (ptr_dst + 1);
		}
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return (NULL);
}
