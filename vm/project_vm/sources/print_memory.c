/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:07:03 by thedupuy          #+#    #+#             */
/*   Updated: 2018/03/05 14:07:07 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_mem(const void *addr, size_t size, size_t i)
{
	char			tab[17];
	unsigned char	*str;
	int				c;

	str = (unsigned char*)addr;
	ft_strcpy(tab, "0123456789abcdef");
	while (i < size)
	{
		c = str[i];
		if (i % 8 == 0)
		{
			ft_printf("%c", tab[c / 16]);
			ft_printf("%c", tab[c % 16]);
		}
		else
		{
			ft_putchar(tab[c / 16]);
			ft_putchar(tab[c % 16]);
		}
		i++;
		if (i % 1 == 0)
			ft_putchar(' ');
		if (i % 32 == 0)
			ft_putchar('\n');
	}
}
