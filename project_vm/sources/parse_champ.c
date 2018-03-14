/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:58:48 by thedupuy          #+#    #+#             */
/*   Updated: 2018/03/07 19:37:58 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		take_opt(char **av, t_data *data, int *i, int ac)
{
	int n;

	n = 0;
	if (ac == ((*i) + 1))
		return (-1);
	if (ft_strcmp("-dump", av[(*i)]) == 0)
	{
		if (av[++(*i)][n] == '-')
			return (-1);
		while (av[(*i)][n])
		{
			if (ft_isdigit(av[(*i)][n]) == 0)
				return (-1);
			n++;
		}
		if (n > 10)
			return (-1);
		data->dump = ft_atol(av[(*i)]);
		if (data->dump > 2147483647)
			return (-1);
		return (1);
	}
	else
		data->vis = 1;
	return (1);
}

int		take_nb_champ(char **av, int *i, t_data *data, int ac)
{
	unsigned char	tab[4096];
	int				fd;
	int				x;
	int				n;

	(*i)++;
	if (ac == (*i))
		return (-1);
	x = ft_atoi(av[(*i)]);
	if (ft_strlen(av[(*i)]) != 1 || (x > 4 || x < 1) || data->c_n[x - 1] != x)
		return (-1);
	(*i)++;
	if (!(ft_strstr(av[(*i)], ".cor\0")))
		return (-1);
	if ((fd = open(av[(*i)], O_RDONLY)) == -1)
		return (-1);
	n = read(fd, tab, 4096);
	tab[n - 1] = '\0';
	if (create_champ(tab, n, data, x) == -1)
		return (-1);
	data->n = 1;
	return (1);
}

int		take_champ(char **av, int i, t_data *data)
{
	unsigned char	tab[4096];
	int				fd;
	int				n;

	if (data->c_n[0] == 0 || data->c_n[1] == 0 || data->c_n[2] == 0 ||
		data->c_n[3] == 0)
		return (-1);
	fd = open(av[i], O_RDONLY);
	if (fd == -1)
		return (-1);
	n = read(fd, tab, 4096);
	if (create_champ(tab, n, data, 0) == -1)
		return (-1);
	return (1);
}

int		create_champ(unsigned char tab[], int n, t_data *data, int x)
{
	t_champ		*champ;

	if ((champ = new_champ()) == NULL)
		return (-1);
	if (tab[0] != 0x00 || tab[1] != 0xea || tab[2] != 0x83 || tab[3] != 0xf3)
		return (-1);
	if (ft_take_name_com(champ, tab, n) == -1)
		return (-1);
	if (x != 0)
		data->c_n[x - 1] = 0;
	champ->n_p = x;
	add_champ(champ, data);
	data->nb_champ++;
	data->nb_champ2 = data->nb_champ;
	return (1);
}

int		parse_shell(t_data *data, int ac, char **av, int i)
{
	while (i != ac)
	{
		if ((ft_strcmp("-dump", av[i]) == 0) || ft_strcmp("-vis", av[i]) == 0)
		{
			if (take_opt(av, data, &i, ac) == -1)
				return (push_er("Wrong dump."));
		}
		else if (ft_strcmp("-n", av[i]) == 0)
		{
			if (data->nb_champ > 3 || take_nb_champ(av, &i, data, ac) == -1)
				return (push_er("Players error."));
		}
		else if (ft_strstr(av[i], ".cor\0"))
		{
			if (data->nb_champ > 3 || take_champ(av, i, data) == -1)
				return (push_er("Players error."));
		}
		else
			return (push_er("Bad argument."));
		i++;
	}
	return (check_player(data));
}
