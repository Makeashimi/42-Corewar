/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:22:27 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/30 11:36:20 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_file(char **str, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*strcpy;
	int		ret;

	ret = 1;
	while (ft_strsrchi(*str, '\n') == -1 && ret)
	{
		strcpy = *str;
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		*str = ft_strjoin(strcpy, buf);
		ft_strdel(&strcpy);
	}
	if (ret == 0 && *str[0] == 0)
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*str;
	static char		*end_of_file = NULL;
	int				i;

	str = (end_of_file == NULL) ? ft_strnew(0) : ft_strdup(end_of_file);
	ft_strdel(&end_of_file);
	if ((i = read_file(&str, fd)) != 1)
	{
		ft_strdel(&str);
		return (i);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = ft_strsub(str, 0, i);
	if (str[i] == '\n')
		end_of_file = ft_strdup(&str[i + 1]);
	ft_strdel(&str);
	return (1);
}
