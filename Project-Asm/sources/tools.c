/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:48:14 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/08 22:42:07 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void					error(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

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
		//ft_printf("str : %s\n", str + i);
		if (ft_space(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static t_instruction	*create_instruction(char *str, int len)
{
	t_instruction	*instruction;

	if (!(instruction = (t_instruction*)malloc(sizeof(t_instruction))))
		error("Malloc error");
	ft_memset(instruction, 0, sizeof(instruction));
	if (!(instruction->name = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		error("Malloc error");
	instruction->name = ft_strncpy(instruction->name, str, len);
	instruction->name[len] = '\0';
	return (instruction);
}

t_instruction			*link_instruction(t_instruction **instruction, char *str, int len)
{
	t_instruction	*tmp;

	if (*instruction == NULL)
	{
		*instruction = create_instruction(str, len);
		return (*instruction);
	}
	tmp = *instruction;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_instruction(str, len);
	return (tmp->next);
}

char					*get_last_instru(t_instruction *instruction)
{
	t_instruction	*tmp;
	
	tmp = instruction;
	//ft_printf("avant %p\n", tmp);
	//ft_printf("avant next %p\n", tmp->next);
	if (tmp == instruction)
		return (tmp->name);
	while (tmp->next != NULL)
	{
		//ft_printf("ydrhcf\n");
		tmp = tmp->next;
	}
	//ft_printf("apres %p\n", tmp);
	return (tmp->name);
}
