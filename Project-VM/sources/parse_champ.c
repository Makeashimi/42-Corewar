/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:58:48 by thedupuy          #+#    #+#             */
/*   Updated: 2018/02/06 16:58:50 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		take_dump(char *av, t_data *data)
{
	int i;

	i = 0;
	if (av[i] == '-')
		return (-1);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0)
			return (-1);
		i++;
	}
	data->dump = ft_atoi(av);
	return (1);
}

int		take_nb_champ(char **av, int *i, t_data *data)
{
	unsigned char	tab[4096];
	int				fd;
	int				x;
	int				n;

	(*i)++;
	x = ft_atoi(av[(*i)]);
	if (ft_strlen(av[(*i)]) != 1 || (x > 4 || x < 1) || data->c_n[x - 1] != x)
		return (-1);
	(*i)++;
	if (!(ft_strstr(av[(*i)], ".cor\0")))
		return (-1);
	if ((fd = open(av[(*i)], O_RDONLY)) == -1)
		return (-1);
	n = read(fd, tab, 4096);
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
	int			i;

	i = n - 1;
	if ((champ = new_champ()) == NULL)
		return (-1);
	while (ft_take_champ(tab, i) != 1)
		i--;
	if ((champ->code = (unsigned char *)malloc(sizeof(unsigned char) * (n - i))) == NULL)
		return (-1);
	ft_memcpy(champ->code, &tab[i], (size_t)n - i);
	if (ft_take_name_com(champ, tab) == -1)
		return (-1);
	if (x != 0)
		data->c_n[x - 1] = 0;
	champ->size = n - i;
	champ->n_p = x;
	add_champ(champ, data);
	data->nb_champ++;
	return (1);
}

int		parse_shell(t_data *data, int ac, char **av)
{
	int i;

	i = 1;
	while (i != ac)
	{
		if ((ft_strcmp("-dump", av[i]) == 0) && i == 1)
		{
			if (take_dump(av[++i], data) == -1)
				return (-1);
		}
		else if (ft_strcmp("-n", av[i]) == 0)
		{
			if (data->nb_champ > 3 || take_nb_champ(av, &i, data) == -1)
				return (-1);
		}
		else if (ft_strstr(av[i], ".cor\0"))
		{
			if (data->nb_champ > 3 || take_champ(av, i, data) == -1)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (check_player(data));
}