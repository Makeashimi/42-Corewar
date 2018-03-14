/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:05:34 by jcharloi          #+#    #+#             */
/*   Updated: 2018/03/07 16:33:41 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		error(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

void		write_output(char *str, t_asm *l_asm, t_instruction *ins)
{
	char	*cpy;
	int		fd;

	if (!(cpy = (char*)malloc(sizeof(char) * (ft_strlen(str) + 5))))
		error("Malloc error");
	ft_bzero(cpy, ft_strlen(str) + 5);
	cpy = strcpy_untilstr(cpy, str, ".s\0");
	cpy = ft_strcat(cpy, ".cor");
	fd = open(cpy, O_RDWR | O_CREAT | O_TRUNC, FILE_RIGHTS);
	assign_size_ins(ins);
	wr_header(fd, l_asm, ins);
	wr_ins(fd, ins);
	ft_printf("Writing output program to %s\n", cpy);
	free(cpy);
}

static int	cmp_label(t_instruction *instruction, char *str)
{
	t_instruction	*cpy;
	int				o;

	cpy = instruction;
	while (cpy != NULL)
	{
		o = 0;
		while (cpy->label[o] != NULL)
		{
			if (ft_strcmp(cpy->label[o], str) == 0)
				return (1);
			o++;
		}
		cpy = cpy->next;
	}
	return (0);
}

void		check_label(t_instruction *instruction, t_asm *l_asm,
												char **argv, int argc)
{
	t_instruction	*tmp;

	tmp = instruction;
	while (tmp != NULL)
	{
		if (tmp->param[0] != NULL && tmp->param[0][0] == LABEL_CHAR)
		{
			if (cmp_label(instruction, tmp->param[0] + 1) == 0)
				error("Wrong label name");
		}
		else if (tmp->param[1] != NULL && tmp->param[1][0] == LABEL_CHAR)
		{
			if (cmp_label(instruction, tmp->param[1] + 1) == 0)
				error("Wrong label name");
		}
		else if (tmp->param[2] != NULL && tmp->param[2][0] == LABEL_CHAR)
		{
			if (cmp_label(instruction, tmp->param[2] + 1) == 0)
				error("Wrong label name");
		}
		tmp = tmp->next;
	}
	write_output(argv[argc - 1], l_asm, instruction);
}
