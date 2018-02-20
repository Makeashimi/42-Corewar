/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:33:18 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/19 19:28:22 by jcharloi         ###   ########.fr       */
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

void	check_next_content(t_asm *l_asm, char *str, char *message, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 1;
	ft_printf("ici : %s\n", str);
	while (str[i] != '\0' && str[i] != '"')
	{
		i++;
		len++;
	}
	if (str[i] == '\0')
	{
		ft_printf("No \"%s\"", message);
		error("");
	}
	check_len(l_asm, c);
	i++;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] != '\0' && str[i] != COMMENT_CHAR)
	{
		ft_printf("Characters after \"%s\"", message);
		error("");
	}
}
