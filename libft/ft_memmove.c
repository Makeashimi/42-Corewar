/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:22:12 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:21:12 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_cpy;

	ptr_cpy = ft_strnew(len);
	if (ptr_cpy == NULL)
		return (NULL);
	ft_memcpy(ptr_cpy, src, len);
	ft_memcpy(dst, ptr_cpy, len);
	free(ptr_cpy);
	return (dst);
}
