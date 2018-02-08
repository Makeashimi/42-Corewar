/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:13:01 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/08 14:30:28 by jcharloi         ###   ########.fr       */
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

void	write_output(char *str)
{
	char 	*cpy;

	if (!(cpy = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		error("Malloc error");
	cpy = strcpy_until(cpy, str, '.');
	ft_printf("Writing output program to %s.cor\n", cpy);
}

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
		free(str);
	}
	tmp = parse_begin(l_asm);
	parse_instructions(l_asm, instruction, tmp);
	write_output(argv[argc - 1]);
	/*while (l_asm != NULL)
	{
		ft_printf("asm : %p\n", l_asm);
		l_asm = l_asm->next;
	}*/
	return (0);
}
