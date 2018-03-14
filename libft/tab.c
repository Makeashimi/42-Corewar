/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taballoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 17:05:01 by jcharloi          #+#    #+#             */
/*   Updated: 2017/12/02 13:45:22 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_taballoc(int *ptr, int size)
{
	int		*copy;

	if (ptr == NULL)
		return ((int*)malloc(size));
	if (!(copy = (int*)malloc(size)))
		return (NULL);
	ft_memcpy(copy, ptr, size);
	ft_memdel((void**)&ptr);
	return (copy);
}

void	tabset(int *tab, int c, int len)
{
	int		i;

	i = 0;
	while (len)
	{
		tab[i] = c;
		len--;
		i++;
	}
}

void	cpy_tab(int *tab1, int *tab2, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		tab1[i] = tab2[i];
		i++;
	}
}

void	cleartab(int *tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		tab[i] = 0;
		i++;
	}
}
