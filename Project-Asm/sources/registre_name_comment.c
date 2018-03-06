/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registre_name_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:02:18 by jcharloi          #+#    #+#             */
/*   Updated: 2018/03/06 21:33:02 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	registerr(t_asm *l_asm, t_asm *tmp, char **str, int i)
{
	int		j;
	int		o;

	o = 0;
	j = 0;
	while (1)
	{
		while (tmp->str[i] != '\0' && tmp->str[i] != '"')
			str[o][j++] = tmp->str[i++];
		if (tmp->str[i] == '\0')
		{
			str[o][j] = '\0';
			i = 0;
			j = 0;
			o++;
			tmp = tmp->next;
			if (!(str[o] = (char*)malloc(sizeof(char) * (l_asm->len + 1))))
				error("Malloc error");
		}
		else if (tmp->str[i] == '"')
		{
			str[o][j] = '\0';
			return ;
		}
	}
}

void	get_comment(t_asm *l_asm, t_asm *tmp, int count, int i)
{
	if (tmp->str[i + 1] == COMMENT_CMD_STRING[1])
	{
		if (!(l_asm->comment = (char**)malloc(sizeof(char*) * (count + 1))))
			error("Malloc error");
		if (!(l_asm->comment[0] = (char*)malloc(sizeof(char) *
															(l_asm->len + 1))))
			error("Malloc error");
		l_asm->comment[count] = NULL;
		while (tmp->str[i] != '"')
			i++;
		i++;
		registerr(l_asm, tmp, l_asm->comment, i);
	}
}

void	get_name(t_asm *l_asm, t_asm *tmp, int count, int i)
{
	while (ft_space(tmp->str[i]) == 1)
		i++;
	if (tmp->str[i + 1] == NAME_CMD_STRING[1])
	{
		if (!(l_asm->champname = (char**)malloc(sizeof(char*) * (count + 1))))
			error("Malloc error");
		if (!(l_asm->champname[0] = (char*)malloc(sizeof(char) *
															(l_asm->len + 1))))
			error("Malloc error");
		l_asm->champname[count] = NULL;
		while (tmp->str[i] != '"')
			i++;
		i++;
		registerr(l_asm, tmp, l_asm->champname, i);
	}
	else
		get_comment(l_asm, tmp, count, i);
}
