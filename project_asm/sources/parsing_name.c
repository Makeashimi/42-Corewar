/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:12:48 by jcharloi          #+#    #+#             */
/*   Updated: 2018/03/09 13:52:22 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PARSING :
** Verifier la taille du nom
** Verifier la taille du comment
** Si c'est un % -> param direct, si r -> param registre de 1 à 16
** else -> indirect
** verifier qu'une instruction existe
** autant de lignes que je veux entre chaque instruction
** autant d'espaces et de tab entre chaque instruction et parametres
** Apres un %: ca n'est pas une instruction, c'est un label
** une virgule entre chaque parametre
** une seule instruction par ligne
** commentaire autorise
** pas 2x label
*/

#include "asm.h"

static void		check_between(char *str, char c, char *message)
{
	char	*test;

	test = NULL;
	if (str[0] == '\0')
		error("Error");
	if (ft_space(str[0]) == 0 && str[0] != '"')
	{
		if (c == NAME_CMD_STRING[ft_strlen(NAME_CMD_STRING) - 1])
			test = ft_strdup(NAME_CMD_STRING);
		else if (c == COMMENT_CMD_STRING[ft_strlen(COMMENT_CMD_STRING) - 1])
			test = ft_strdup(COMMENT_CMD_STRING);
		ft_printf("Syntax error between %s and \"%s\"", test, message);
		error("");
	}
	ft_strdel(&test);
}

static void		check_end_line(t_asm *l_asm, t_asm *tmp, int *i, char *message)
{
	while (ft_space(tmp->str[*i]) == 1)
		(*i)++;
	if (tmp->str[*i] == '\0' || tmp->str[*i] != '"' || tmp->str[*i] == '\n')
	{
		ft_printf(
"Syntax error with the \"%s\" or no \"%s\" found", message, message);
		error("");
	}
	(*i)++;
	while (tmp->str[*i] != '\0' && tmp->str[*i] != '"')
	{
		(*i)++;
		l_asm->len++;
	}
}

static t_asm	*check_content(t_asm *l_asm, t_asm *tmp, char c, char *mes)
{
	t_asm	*cpy;
	int		i;
	int		count;

	count = 1;
	i = 0;
	l_asm->len = 0;
	cpy = tmp;
	while (tmp->str[i] != '\0' && tmp->str[i] != c)
		i++;
	tmp->str[i] != '\0' ? i++ : i;
	check_between(tmp->str + i, c, mes);
	check_end_line(l_asm, tmp, &i, mes);
	if (tmp->str[i] == '\0')
	{
		cpy = tmp;
		i = get_last_line(l_asm, &tmp, &count, mes);
		while (tmp->str[i] != '\0' && tmp->str[i] != '"')
			i++;
	}
	i++;
	check_characters_after(tmp->str + i, mes);
	check_len(l_asm, c);
	get_name(l_asm, cpy, count, 0);
	return (tmp);
}

static t_asm	*is_name_or_comment(t_asm *l_asm, t_asm *tmp, int i)
{
	if (ft_strncmp(NAME_CMD_STRING, tmp->str + i,
											ft_strlen(NAME_CMD_STRING)) == 0)
	{
		tmp = check_content(l_asm, tmp,
	NAME_CMD_STRING[ft_strlen(NAME_CMD_STRING) - 1], "name of champ");
		next_tmp(&tmp, "Missing comment");
		tmp = check_content(l_asm, tmp,
	COMMENT_CMD_STRING[ft_strlen(COMMENT_CMD_STRING) - 1], COMMENT_CMD_STRING);
	}
	else if (ft_strncmp(COMMENT_CMD_STRING, tmp->str + i,
									ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		tmp = check_content(l_asm, tmp,
	COMMENT_CMD_STRING[ft_strlen(COMMENT_CMD_STRING) - 1], COMMENT_CMD_STRING);
		next_tmp(&tmp, "Missing name");
		tmp = check_content(l_asm, tmp,
	NAME_CMD_STRING[ft_strlen(NAME_CMD_STRING) - 1], "name of champ");
	}
	else
		error("Syntax error with the .name or .comment");
	return (tmp);
}

t_asm			*begin_parse(t_asm *l_asm)
{
	t_asm	*tmp;
	int		i;

	i = 0;
	tmp = l_asm;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		error("Nothing found");
	while (ft_space(tmp->str[i]) == 1)
		i++;
	tmp = is_name_or_comment(l_asm, tmp, i);
	tmp = tmp->next;
	if (tmp == NULL)
		error("Nothing found after .name/.comment");
	return (tmp);
}
