/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:03:36 by jcharloi          #+#    #+#             */
/*   Updated: 2017/07/24 11:14:37 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		whatsize(wchar_t c)
{
	if (c >= 1114112)
		return (0);
	else if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	return (4);
}

void	print_wchart(wchar_t c)
{
	if (c >= 1114112)
		return ;
	if (c < 128)
	{
		ft_putchar(c);
		return ;
	}
	else if (c < 2048)
	{
		ft_putchar(192 | (c >> 6));
		ft_putchar(128 | (c & 63));
		return ;
	}
	else if (c < 65536)
	{
		ft_putchar(224 | (c >> 12));
		ft_putchar(128 | ((c >> 6) & 63));
		ft_putchar(128 | (c & 63));
		return ;
	}
	ft_putchar(240 | (c >> 18));
	ft_putchar(128 | ((c >> 12) & 63));
	ft_putchar(128 | ((c >> 6) & 63));
	ft_putchar(128 | (c & 63));
	return ;
}

void	ft_putwchart(wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		print_wchart(str[i]);
		i++;
	}
}
