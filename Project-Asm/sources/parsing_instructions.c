/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:47 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/09 22:28:20 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** T_REG -> 1
** T_DIR -> 2
** T_DIR ou T_REG -> 3
** (NEVER APPEARED)T_IND -> 4
** T_REG ou T_IND -> 5
** T_DIR ou T_IND -> 6
** T_DIR ou T_REG ou T_IND -> 7
** ------------------------
** if (g_op_tab[instruction->index].arg[0] == 1)
**	 T_REG needed
** else if (g_op_tab[instruction->index].arg[0] == 2)
** 	 T_DIR needed
** else if (g_op_tab[instruction->index].arg[0] == 3)
** 	 T_DIR OU T_REG needed
** else if (g_op_tab[instruction->index].arg[0] == 5)
** 	 T_REG ou T_IND needed
** else if (g_op_tab[instruction->index].arg[0] == 6)
** 	 T_DIR ou T_IND needed
** else if (g_op_tab[instruction->index].arg[0] == 7)
**	 T_DIR OU T_REG OU T_IND needed
*/

char	*move_to_param(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && ft_space(str[i]) == 0)
		i++;
	if (str[i] == 0)
		error("No parameters");
	while (str[i] != '\0' && ft_space(str[i]) == 1)
		i++;
	if (str[i] == 0)
		error("No parameters");
	return (str + i);
}

char	*move_to_instru(t_asm *tmp)
{
	int		i;

	i = 0;
	if (ft_space(tmp->str[i]) == 1)
	{
		while (ft_space(tmp->str[i]) == 0)
			i++;
	}
	while (tmp->str[i] != LABEL_CHAR)
		i++;
	i++;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	if (tmp->str[i] == '\0' || tmp->str[i] == COMMENT_CHAR)
	{
		i = 0;
		tmp = tmp->next;
	}
	while (tmp != NULL && is_all_space(tmp->str) == 1)
	{
		i = 0;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		error("No instructions found");
	while (ft_space(tmp->str[i]) == 1)
		i++;
	return (tmp->str + i);
}

void	parse_instructions(t_instruction *instruction, t_asm *tmp)
{
	int		ret;
	int		i;
	int		o;

	ret = 0;
	o = 0;
	i = 0;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		error("Nothing found after name/comment");
	while (ft_space(tmp->str[i]) == 1)
		i++;
	ret = is_label(instruction, tmp->str + i);
	if (ret == 1)
	{
		tmp->str = move_to_instru(tmp);
		i = 0;
	}
	if (is_name_instru(instruction, tmp->str + i) == 0)
		error("Syntax error with the label or the instruction");
	tmp->str = move_to_param(tmp->str + i);
	if (check_param(instruction, tmp->str) == 0)
		error("Syntax error with the params of the instruction");
}
