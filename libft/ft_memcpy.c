/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:41:32 by jcharloi          #+#    #+#             */
/*   Updated: 2017/07/27 16:45:07 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;
	int				i;

	ptr_src = (unsigned char*)src;
	ptr_dst = (unsigned char*)dst;
	i = 0;
	while (n != 0)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
		n--;
	}
	return (ptr_dst);
}
