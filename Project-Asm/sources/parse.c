/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/28 19:40:52 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int 	is_confurm(char c)
{
	int		i;

	i = 0;
	ft_printf("c : %c\n", c);
	while (LABEL_CHARS[i] != '\0')
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_label(char *str)
{
	int		i;

	i = 0;
	//ft_printf("str avant : %s\n", str);
	while (str[i] != LABEL_CHAR)
	{
		ft_printf("str avant : %s\n", str + i);
		if (is_confurm(str[i]) == 0)
			error("Syntax error with the label");
		i++;
	}
}

void	parse_instructions(t_asm *tmp)
{
	char	*cpy;
	int		i;
	int 	o;

	o = 0;
	i = 0;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	//ft_printf("str       : %s\n", tmp->str + i);
	cpy = tmp->str;
	o = i;
	while (ft_isalnum(cpy[o]) == 1)
		o++;
	ft_printf("cpy[o] : %c\n", cpy[o]);
	if (cpy[o] == LABEL_CHAR)
	{
		check_label(tmp->str + i);
		tmp->str = cpy + ++o;
		while (ft_space(*tmp->str) == 1)
			tmp->str++;
	}
	else
		tmp->str = tmp->str + i;
	ft_printf("str apres : %s\n", tmp->str);
}
