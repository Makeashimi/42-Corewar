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

int					push_er(char *s)
{
	ft_putendl(s);
	return (-1);
}

void				print_tab(const void *addr, size_t size, size_t i)
{
	char			tab[17];
	unsigned char	*str;
	int				c;

	ft_strcpy(tab, "0123456789abcdef");
	str = (unsigned char*)addr;
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
		if (i % 64 == 0)
			ft_putchar('\n');
	}
}

static int			ft_finish(t_data *data)
{
	int				i;
	t_champ			*champ;

	i = data->last_l;
	champ = data->champ;
	if (data->dump == 0)
		print_mem(data->arene, 4096, 0);
	else if (i > 0 && i <= data->nb_champ2)
	{
		if (data->vis == 1)
			print_tab(data->arene, 4096, 0);
		while (i != champ->n_p)
			champ = champ->next;
		ft_printf("Le joueur %d(%s) a gagne\n", data->last_l, champ->name);
	}
	return (0);
}

int					main(int ac, char **av)
{
	t_data			*data;
	int				i;

	i = 1;
	if (ac < 3)
		return (-1);
	if ((data = init_data()) == NULL)
		return (push_er("Init malloc error"));
	if (parse_shell(data, ac, av, 1) == -1)
		return (-1);
	init_champ(data);
	launch_champ(data);
	init_instruction(data);
	while (data->ctd > 0 && data->dump != 0 && data->proc)
	{
		battle(data);
		if (i == data->ctd && (i = 1))
			check_to_die(data);
		else
			i++;
		data->dump--;
		if (data->ctd > 0)
			data->tour++;
	}
	return (ft_finish(data));
}
