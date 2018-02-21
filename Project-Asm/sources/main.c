/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:13:01 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/21 21:11:58 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Name/Comment sur plusieurs lignes
** Label à la fin
** Ajouter une derniere ligne obligatoirement ?
*/

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(-1);
}

t_asm	*create_str(char *str)
{
	t_asm	*tmp;

	if (!(tmp = (t_asm*)malloc(sizeof(t_asm))))
		error("Malloc error");
	ft_memset(tmp, 0, sizeof(t_asm));
	if (!(tmp->str = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		error("Malloc error");
	tmp->str = ft_strcpy(tmp->str, str);
	return (tmp);
}

t_asm	*link_str(t_asm *l_asm, char *str)
{
	t_asm	*tmp;

	tmp = l_asm;
	if (tmp == NULL)
	{
		l_asm = create_str(str);
		return (l_asm);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_str(str);
	return (l_asm);
}

int		cmp_label(t_instruction *instruction, char *str)
{
	t_instruction	*cpy;

	cpy = instruction;
	while (cpy != NULL)
	{
		while (cpy != NULL && cpy->label == NULL)
			cpy = cpy->next;
		if (cpy == NULL)
			return (0);
		if (ft_strcmp(str, cpy->label) == 0)
			return (1);
		cpy = cpy->next;
	}
	return (0);
}

void	check_label(t_instruction *instruction)
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
}

void	write_output(char *str, t_asm *l_asm, t_instruction *ins)
{
	char	*cpy;
	int		fd;

	(void)ins;
	(void)l_asm;
	if (!(cpy = (char*)malloc(sizeof(char) * (ft_strlen(str) + 5))))
		error("Malloc error");
	cpy = strcpy_until(cpy, str, '.');
	cpy = ft_strcat(cpy, ".cor");
	fd = open(cpy, O_RDWR | O_CREAT);
	ft_printf("Writing output program to %s\n", cpy);
}

int		check_next_tmp(t_asm *tmp)
{
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_instruction	*cpy;
	t_instruction	*instruction;
	t_asm			*l_asm;
	t_asm			*tmp;
	char			*str;
	int				fd;

	l_asm = NULL;
	instruction = NULL;
	if (argc < 2)
		error("Usage : ./asm <filename.s>");
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Open error, can't read source file %s", argv[argc - 1]);
		error("");
	}
	while (get_next_line(fd, &str) == 1)
	{
		l_asm = link_str(l_asm, str);
		free(str);
	}
	tmp = begin_parse(l_asm);
	int i = 0;
	while (l_asm->champname[i] != NULL)
		ft_printf("l_asm->champname: %s\n", l_asm->champname[i++]);
	i = 0;
	while (l_asm->comment[i] != NULL)
		ft_printf("l_asm->comment : %s\n", l_asm->comment[i++]);
	while (tmp != NULL)
	{
		cpy = link_instruction(&instruction);
		tmp = parse_instructions(cpy, tmp, 0, 0);
		tmp = tmp->next;
		if (check_next_tmp(tmp) == 0)
			break ;
	}
	check_label(instruction);
	write_output(argv[argc - 1], l_asm, instruction);
	return (0);
}
