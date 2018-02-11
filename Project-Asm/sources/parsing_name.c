/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:12:48 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/11 15:35:47 by jcharloi         ###   ########.fr       */
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

static void		check_between(char *str, char c, int i, char *message)
{
	char	*test;

	test = NULL;
	if (ft_space(str[i + 1]) == 0 && str[i + 1] != '"')
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

static void		check_content(t_asm *l_asm, char *str, char c, char *message)
{
	int		i;

	i = 0;
	while (str[i] != c)
		i++;
	check_between(str, c, i, message);
	i++;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] == '\0' || str[i] != '"' || str[i] == '\n')
	{
		ft_printf(
"Syntax error with the \"%s\" or no \"%s\" found", message, message);
		error("");
	}
	check_next_content(l_asm, str + i, message, c);
}

static t_asm	*is_name_or_comment(t_asm *l_asm, t_asm *tmp, int i)
{
	if (ft_strncmp(NAME_CMD_STRING, tmp->str + i,
										ft_strlen(NAME_CMD_STRING)) == 0)
	{
		check_content(l_asm, tmp->str + i, 'e', "name of champ");
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		while (ft_space(tmp->str[i]) == 1)
			i++;
		check_content(l_asm, tmp->str + i, 't', "comment");
	}
	else if (ft_strncmp(COMMENT_CMD_STRING, tmp->str + i,
									ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		check_content(l_asm, tmp->str + i, 't', "comment");
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		while (ft_space(tmp->str[i]) == 1)
			i++;
		check_content(l_asm, tmp->str + i, 'e', "name of champ");
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
	while (ft_space(tmp->str[i]) == 1)
		i++;
	tmp = is_name_or_comment(l_asm, tmp, i);
	tmp = tmp->next;
	return (tmp);
}
