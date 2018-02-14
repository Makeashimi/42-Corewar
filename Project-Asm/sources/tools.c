/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:48:14 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/14 15:04:39 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						ft_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int						is_all_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == COMMENT_CHAR)
			return (1);
		if (ft_space(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static t_instruction	*create_instruction(void)
{
	t_instruction	*instruction;

	if (!(instruction = (t_instruction*)malloc(sizeof(t_instruction))))
		error("Malloc error");
	ft_memset(instruction, 0, sizeof(t_instruction));
	return (instruction);
}

t_instruction			*link_instruction(t_instruction **instruction)
{
	t_instruction	*tmp;

	if (*instruction == NULL)
	{
		*instruction = create_instruction();
		return (*instruction);
	}
	tmp = *instruction;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_instruction();
	return (tmp->next);
}

t_instruction			*get_last_instru(t_instruction *instruction)
{
	t_instruction	*tmp;

	tmp = instruction;
	if (tmp == instruction)
		return (tmp);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
