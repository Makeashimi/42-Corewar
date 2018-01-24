/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:13:01 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/18 18:14:10 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

t_asm	*create_str(char *str)
{
	t_asm	*tmp;

	if (!(tmp = (t_asm*)malloc(sizeof(t_asm))))
		error("Malloc error");
	ft_memset(tmp, 0, sizeof(t_asm));
	if (!(tmp->str = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		error("Malloc error");
	tmp->str = ft_strcpy(tmp->str, str);
	return (tmp);
}

t_asm	*link_str(t_asm *l_asm, char *str)
{
	t_asm	*tmp;

	tmp = l_asm;
	if (tmp == NULL)
	{
		l_asm = create_str(str);
		return (l_asm);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_str(str);
	return (l_asm);
}

int		main(void)
{
	t_asm	*l_asm;
	char	*str;

	l_asm = NULL;
	while (get_next_line(0, &str) == 1)
	{
		l_asm = link_str(l_asm, str);
		free(str);
	}
	parse_asm(l_asm);
	/*while (l_asm != NULL)
	{
		ft_printf("asm : %s\n", l_asm->str);
		l_asm = l_asm->next;
	}*/
	return (0);
}
