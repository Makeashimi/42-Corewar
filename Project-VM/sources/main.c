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
#include "corewar.h"

int		ft_take_champ(unsigned char *tab, int i)
{
	if (tab[i - 1] == 0x00 && tab[i - 2] == 0x00 && tab[i - 3] == 0x00 && 
		tab[i - 4] == 0x00 && tab[i - 5] == 0x00)
		return (1);
	return (0);
}

void 	print_tab(const void *addr, size_t size)
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
}

int main(int ac, char **av)
{
	t_data	*data;
	t_cor	*tmp;

	if (ac < 3)
		return (-1);
	if ((data = init_data()) == NULL)
		return (-1);
	if (parse_shell(data, ac, av) == -1)
		return (-1);
	init_champ(data);
	launch_champ(data);
	tmp = data->proc;
	while (tmp)
	{
		if (*tmp->ptr == 0x02)
			printf("%s\n", "cool story bro");
		print_proc(tmp);
		tmp = tmp->next;
	}
	print_tab(data->arene, 4096);
	return (0);
}