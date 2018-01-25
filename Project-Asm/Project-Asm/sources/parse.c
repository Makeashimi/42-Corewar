/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/25 19:27:06 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_instructions(t_asm *tmp)
{
	int		i;
	int 	o;

	o = 0;
	i = 0;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	ft_printf("str : %s\n", tmp->str + i);
	while (tmp->str[i] != '\0' && tmp->str[i] != ':')
	{
		o = 0;
		
		i++;
	}
}