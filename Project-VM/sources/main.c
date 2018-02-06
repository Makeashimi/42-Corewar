/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:41:35 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/18 17:41:46 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../libft/libft.h"

int		ft_take_champ(unsigned char *tab, int i)
{
	if (tab[i - 1] == 0x00 && tab[i - 2] == 0x00 && tab[i - 3] == 0x00 && 
		tab[i - 4] == 0x00 && tab[i - 5] == 0x00)
		return (1);
	return (0);
}

void 	print_memory(const void *addr, size_t size)
{
	char			tab[16] = "0123456789abcdef";
	unsigned char	*str;
	size_t			i;
	int				c;
	int				j;
	int				count;

	count = 0;
	str = (unsigned char*)addr;
	i = 0;
	while (i < size)
	{
		c = str[i];
		ft_putchar(tab[c / 16]);
		ft_putchar(tab[c % 16]);
		i++;
		count++;
		if (i % 1 == 0)
			ft_putchar(' ');
		if (i % 64 == 0)
		{
			count = 0;
			j = 0;
			ft_putchar('\n');
		}
	}
	if (count != 0)
	{
		j = 16 - count;
		if (i % 2 == 1)
			ft_putchar(' ');
		while (j > 0)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			if (j % 2 == 0)
				ft_putchar(' ');
			j--;
		}
		j = 0;
		ft_putchar('\n');
	}
}

int main(int ac, char **av)
{
	unsigned char *tab;
	unsigned char champ[4096];
	int fd;
	int i;
	int n;

	i = 0;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	i = read(fd, champ, 4096);
	printf("%d\n", i);
	print_memory(champ, i);
	tab = (unsigned char *)malloc(sizeof(unsigned char) * 4096);
	n = i - 1;
	while (ft_take_champ(champ, n) != 1)
		n--;
	printf("%d\n", n);
	printf("%d\n", i);
	memcpy(tab, &champ[n], ((size_t)i - n));
	print_memory(tab, 4096);
	return (0);
}
