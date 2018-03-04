/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:13:01 by jcharloi          #+#    #+#             */
/*   Updated: 2018/03/04 19:02:51 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int		check_next_tmp(t_asm *tmp)
{
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	return (1);
}

void	parse_next(t_instruction **instruction, t_asm *tmp)
{
	t_instruction	*cpy;
	int				o;

	while (tmp != NULL)
	{
		cpy = link_instruction(instruction);
		tmp = parse_instructions(cpy, tmp, 0);
		if (tmp != NULL)
			tmp = tmp->next;
		o = 0;
		if (check_next_tmp(tmp) == 0)
			break ;
	}
}

void	remove_asm(t_asm **l_asm, int i)
{
	t_asm	*tmp;
	t_asm	*next;

	tmp = *l_asm;
	while (tmp->champname[i] != NULL)
	{
		ft_strdel(&tmp->champname[i]);
		i++;
	}
	free(tmp->champname);
	i = 0;
	while (tmp->comment[i] != NULL)
	{
		ft_strdel(&tmp->comment[i]);
		i++;
	}
	free(tmp->comment);
	while (tmp != NULL)
	{
		next = tmp->next;
		// ft_printf("this is tmp: %s\n", tmp->str);
		//if (tmp->str != NULL)
		//	free(tmp->str);
		free(tmp);
		tmp = next;
	}
}

// void	remove_instruction(t_instruction **instruction, int i)
// {
// 	t_instruction	*tmp;
// 	t_instruction	*next;

// 	tmp = *instruction;
// 	(void)i;
// 	tmp = *instruction;
// 	while (tmp != NULL)
// 	{
// 		next = tmp->next;
// 		//ft_strdel(&tmp->label);
// 		ft_strdel(&tmp->name);
// 		free(tmp->param[0]);
// 		free(tmp->param[1]);
// 		free(tmp->param[2]);
// 		free(tmp);
// 		tmp = next;
// 	}
// }

int		main(int argc, char **argv)
{
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
		//ft_printf("this is str: %s\n", str);
		free(str);
	}

	tmp = begin_parse(l_asm);
	parse_next(&instruction, tmp);
	check_label(instruction, l_asm, argv, argc);
	remove_asm(&l_asm, 0);
	//while(1);
	//remove_instruction(&instruction, 0);
	return (0);
}
