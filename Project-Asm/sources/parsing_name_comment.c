/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_name_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:12:48 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/11 14:51:21 by varichar         ###   ########.fr       */
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
*/

#include "asm.h"

void	check_len(t_asm *l_asm, int len, char c, char *str)
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

void	check_next_content(t_asm *l_asm, char *str, char *message, char c)
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

void	check_content(t_asm *l_asm, char *str, int i, char c, char *message)
{
	char	*test;

	test = NULL;
	while (str[i] != c)
		i++;
	if (ft_space(str[i + 1]) == 0 && str[i + 1] != '"')
	{
		if (c == 'e')
			test = ft_strdup(NAME_CMD_STRING);
		else if (c == 't')
			test = ft_strdup(COMMENT_CMD_STRING);
		ft_printf("Syntax error between %s and \"%s\"", test, message);
		error("");
	}
	i++;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] == '\0' || str[i] != '"' || str[i] == '\n')
	{
		ft_printf(
"Syntax error with the \"%s\" or no \"%s\" found", message, message);
		error("");
	}
	ft_strdel(&test);
	check_next_content(l_asm, str + i, message, c);
}

t_asm	*is_name_or_comment(t_asm *l_asm, t_asm *tmp, int i)
{
	if (ft_strncmp(NAME_CMD_STRING, tmp->str + i,
										ft_strlen(NAME_CMD_STRING)) == 0)
	{
		check_content(l_asm, tmp->str, i, 'e', "name of champ");
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		while (ft_space(tmp->str[i]) == 1)
			i++;
		check_content(l_asm, tmp->str, i, 't', "comment");
	}
	else if (ft_strncmp(COMMENT_CMD_STRING, tmp->str + i,
									ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		check_content(l_asm, tmp->str, i, 't', "comment");
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		while (ft_space(tmp->str[i]) == 1)
			i++;
		check_content(l_asm, tmp->str, i, 'e', "name of champ");
	}
	else
		error("Syntax error with the .name or .comment");
	return (tmp);
}

t_asm	*begin_parse(t_asm *l_asm)
{
	t_asm	*tmp;
	int		i;

	i = 0;
	tmp = l_asm;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	tmp = is_name_or_comment(l_asm, tmp, i);
	tmp = tmp->next;
	return (tmp);
}