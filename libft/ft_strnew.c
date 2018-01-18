/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:00:36 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/09 14:44:26 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr_malloc;

	ptr_malloc = (char*)malloc(size + 1);
	if (ptr_malloc == NULL)
		return (NULL);
	ft_bzero(ptr_malloc, size + 1);
	return (ptr_malloc);
}
