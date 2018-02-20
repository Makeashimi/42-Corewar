/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:12:48 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/19 19:32:16 by jcharloi         ###   ########.fr       */
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
	if (ft_space(str[0]) == 0 && str[0] != '"')
	{
		if (c == 'e')
			test = ft_strdup(NAME_CMD_STRING);
		else if (c == 't')
			test = ft_strdup(COMMENT_CMD_STRING);
		ft_printf("Syntax error between %s and \"%s\"", test, message);
		error("");
	}
	ft_strdel(&test);
}

int				count_content(t_asm *l_asm, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '"')
	{
		l_asm->len++;
		i++;
	}
	if (str[i] == '"')
		return (1);
	return (0);
}

void			registerr(t_asm *l_asm, t_asm *tmp, char **str, int i)
{
	int		j;
	int		o;

	o = 0;
	j = 0;
	while (1)
	{
		while (tmp->str[i] != '\0' && tmp->str[i] != '"')
			str[o][j++] = tmp->str[i++];
		if (tmp->str[i] == '\0')
		{
			str[o][j] = '\0';
			i = 0;
			j = 0;
			o++;
			tmp = tmp->next;
			if (!(str[o] = (char*)malloc(sizeof(char) * (l_asm->len + 1))))
				error("Malloc error");
		}
		else if (tmp->str[i] == '"')
		{
			str[o][j] = '\0';
			return ;
		}
	}
}

void			get_name_comment(t_asm *l_asm, t_asm *tmp, int count, int i)
{
	int		o;
	int		j;

	j = 0;
	o = 0;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	if (tmp->str[i + 1] == NAME_CMD_STRING[1])
	{
		if (!(l_asm->champname = (char**)malloc(sizeof(char*) * (count + 1))))
			error("Malloc error");
		if (!(l_asm->champname[o] = (char*)malloc(sizeof(char) *
															(l_asm->len + 1))))
			error("Malloc error");
		l_asm->champname[count] = NULL;
		while (tmp->str[i] != '"')
			i++;
		i++;
		registerr(l_asm, tmp, l_asm->champname, i);
	}
	else if (tmp->str[i + 1] == COMMENT_CMD_STRING[1])
	{
		if (!(l_asm->comment = (char**)malloc(sizeof(char*) * (count + 1))))
			error("Malloc error");
		if (!(l_asm->comment[o] = (char*)malloc(sizeof(char) *
															(l_asm->len + 1))))
			error("Malloc error");
		l_asm->comment[count] = NULL;
		while (tmp->str[i] != '"')
			i++;
		i++;
		registerr(l_asm, tmp, l_asm->comment, i);
	}
}

static t_asm	*check_content(t_asm *l_asm, t_asm *tmp, char c, char *message)
{
	t_asm	*cpy;
	int		i;
	int		test;
	int		count;

	count = 1;
	test = 0;
	i = 0;
	l_asm->len = 0;
	cpy = tmp;
	while (tmp->str[i] != c)
		i++;
	i++;
	check_between(tmp->str + i, c, message);
	while (ft_space(tmp->str[i]) == 1)
		i++;
	if (tmp->str[i] == '\0' || tmp->str[i] != '"' || tmp->str[i] == '\n')
	{
		ft_printf(
"Syntax error with the \"%s\" or no \"%s\" found", message, message);
		error("");
	}
	i++;
	while (tmp->str[i] != '\0' && tmp->str[i] != '"')
	{
		i++;
		l_asm->len++;
	}
	if (tmp->str[i] == '\0')
	{
		cpy = tmp;
		while (tmp != NULL && test == 0)
		{
			tmp = tmp->next;
			test = count_content(l_asm, tmp->str);
			count++;
		}
		if (tmp == NULL)
		{
			ft_printf("No \"%s\"", message);
			error("");
		}
		i = 0;
		check_len(l_asm, c);
		while (tmp->str[i] != '"')
			i++;
	}
	i++;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	if (tmp->str[i] != '\0' && tmp->str[i] != COMMENT_CHAR)
	{
		ft_printf("Characters after \"%s\"", message);
		error("");
	}
	get_name_comment(l_asm, cpy, count, 0);
	return (tmp);
}

static t_asm	*is_name_or_comment(t_asm *l_asm, t_asm *tmp, int i)
{
	if (ft_strncmp(NAME_CMD_STRING, tmp->str + i,
										ft_strlen(NAME_CMD_STRING)) == 0)
	{
		tmp = check_content(l_asm, tmp, 'e', "name of champ");
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		tmp = check_content(l_asm, tmp, 't', "comment");
	}
	else if (ft_strncmp(COMMENT_CMD_STRING, tmp->str + i,
									ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		tmp = check_content(l_asm, tmp, 't', "comment");
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		tmp = check_content(l_asm, tmp, 'e', "name of champ");
	}
	else
		error("Syntax error with the .name or .comment");
	return (tmp);
}

t_asm			*begin_parse(t_asm *l_asm)
{
	t_asm	*tmp;
	t_asm	*cpy;
	int		i;

	i = 0;
	tmp = l_asm;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		error("Nothing found");
	while (ft_space(tmp->str[i]) == 1)
		i++;
	cpy = tmp;
	tmp = is_name_or_comment(l_asm, tmp, i);
	tmp = tmp->next;
	if (tmp == NULL)
		error("Nothing found after .name/.comment");
	return (tmp);
}
