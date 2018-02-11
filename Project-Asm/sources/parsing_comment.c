/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:33:18 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/11 15:34:42 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_len(t_asm *l_asm, int len, char c, char *str)
{
	if (c == 'e')
	{
		if (len > PROG_NAME_LENGTH)
		{
			ft_printf("Champion name too long (Max lengh : %d)",
														PROG_NAME_LENGTH);
			error("");
		}
		if (!(l_asm->champname = (char*)malloc(sizeof(char) * (len + 1))))
			error("Malloc error");
		l_asm->champname = ft_strncpy(l_asm->champname, str + 1, len);
		l_asm->champname[len] = '\0';
	}
	else if (c == 't')
	{
		if (len > COMMENT_LENGTH)
		{
			ft_printf("Comment too long (Max lengh : %d)", COMMENT_LENGTH);
			error("");
		}
		if (!(l_asm->comment = (char*)malloc(sizeof(char) * (len + 1))))
			error("Malloc error");
		l_asm->comment = ft_strncpy(l_asm->comment, str + 1, len);
		l_asm->comment[len] = '\0';
	}
}

void		check_next_content(t_asm *l_asm, char *str, char *message, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 1;
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
	check_len(l_asm, len, c, str);
	i++;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] != '\0' && str[i] != COMMENT_CHAR)
	{
		ft_printf("Characters after \"%s\"", message);
		error("");
	}
}
