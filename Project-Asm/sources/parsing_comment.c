/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:33:18 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/22 12:03:12 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_len(t_asm *l_asm, char c)
{
	if (c == 'e')
	{
		if (l_asm->len > PROG_NAME_LENGTH)
		{
			ft_printf("Champion name too long (Max lengh : %d)",
														PROG_NAME_LENGTH);
			error("");
		}
	}
	else if (c == 't')
	{
		if (l_asm->len > COMMENT_LENGTH)
		{
			ft_printf("Comment too long (Max lengh : %d)", COMMENT_LENGTH);
			error("");
		}
	}
}

int		count_content(t_asm *l_asm, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '"')
	{
		l_asm->len++;
		i++;
	}
	if (str[i] == '"')
		return (1);
	return (0);
}

void	check_characters_after(char *str, char *message)
{
	int		i;

	i = 0;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] != '\0' && str[i] != COMMENT_CHAR)
	{
		ft_printf("Characters after \"%s\"", message);
		error("");
	}
}

int		get_last_line(t_asm *l_asm, t_asm **tmp, int *count, char *mes)
{
	int		test;

	test = 0;
	while (*tmp != NULL && test == 0)
	{
		*tmp = (*tmp)->next;
		l_asm->len++;
		test = count_content(l_asm, (*tmp)->str);
		(*count)++;
	}
	if (*tmp == NULL)
	{
		ft_printf("No \"%s\"", mes);
		error("");
	}
	return (0);
}
