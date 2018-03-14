/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:16:50 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:20:35 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pt_b;

	pt_b = (unsigned char*)b;
	while (len > 0)
	{
		*pt_b++ = (unsigned char)c;
		len--;
	}
	return (b);
}
