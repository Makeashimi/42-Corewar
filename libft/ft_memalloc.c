/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:23:54 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:24:47 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr_ma;

	ptr_ma = malloc(size);
	if (ptr_ma == NULL)
		return (NULL);
	ft_bzero(ptr_ma, size);
	return (ptr_ma);
}
