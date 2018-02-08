/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_name_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:12:48 by jcharloi          #+#    #+#             */
/*   Updated: 2018/02/03 14:37:10 by jcharloi         ###   ########.fr       */
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

void	next_name(char *str)
{
	int		i;
	int 	len;

	len = 0;
	i = 1;
	while (str[i] != '\0' && str[i] != '"')
	{
		i++;
		len++;
	}
	if (str[i] == '\0')
		error("No champion name");
	//ft_printf("%d\n", len);
	if (len > PROG_NAME_LENGTH)
		error("Champion name too long (Max lengh : 128)");
	i++;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] != '\0' && str[i] != '#')
		error("Characteres after \"name of champ\"");
	//ft_printf("i : %c\n", str[i]);
}

void	next_comment(char *str)
{
	int		i;
	int 	len;

	len = 0;
	i = 1;
	//ft_printf("str : %s\n", str + i);
	while (str[i] != '\0' && str[i] != '"')
	{
		i++;
		len++;
	}
	//ft_printf("str : %s\n", str + i);
	if (str[i] == '\0')
		error("No comment");
	//ft_printf("%d\n", len);
	if (len > COMMENT_LENGTH)
		error("Comment too long (Max lengh : 2048)");
	i++;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] != '\0' && str[i] != COMMENT_CHAR)
		error("Characteres after \"comment\"");
	//ft_printf("i : %c\n", str[i]);
}

void	check_comment(char *str, int i)
{
	while (str[i] != 't')
		i++;
	if (ft_space(str[i + 1]) == 0 && str[i + 1] != '"')
		error("Syntax error between .comment and \"comment\"");
	i++;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] == '\0' || str[i] != '"' || str[i] == '\n')
		error("Syntax error with the \"comment\" or no \"comment\" found");
	next_comment(str + i);
}

void	check_name(char *str, int i)
{
	while (str[i] != 'e')
		i++;
	//ft_printf("str : %s\n", tmp->str + i);
	if (ft_space(str[i + 1]) == 0 && str[i + 1] != '"')
		error("Syntax error between .name and \"name of champ\"");
	i++;
	while (ft_space(str[i]) == 1)
		i++;
	//ft_printf("str : %s\n", tmp->str + i);
	if (str[i] == '\0' || str[i] != '"' || str[i] == '\n')
		error("Syntax error with the \"name of champ\" or no \"name of champ\" found");
	next_name(str + i);
}

t_asm	*parse_begin(t_asm *l_asm)
{
	t_asm	*tmp;
	int		i;

	i = 0;
	tmp = l_asm;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	while (ft_space(tmp->str[i]) == 1)
		i++;
	//ft_printf("str : %s\n", tmp->str + i);
	if (ft_strncmp(NAME_CMD_STRING, tmp->str + i, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		check_name(tmp->str, i);
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		while (ft_space(tmp->str[i]) == 1)
			i++;
		//ft_printf("str : %s\n", tmp->str + i);
		check_comment(tmp->str, i);
	}
	else if (ft_strncmp(COMMENT_CMD_STRING, tmp->str + i, ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		check_comment(tmp->str, i);
		tmp = tmp->next;
		while (tmp != NULL && is_all_space(tmp->str) == 1)
			tmp = tmp->next;
		while (ft_space(tmp->str[i]) == 1)
			i++;
		//ft_printf("str : %s\n", tmp->str + i);
		check_name(tmp->str, i);
	}
	else
		error("Syntax error with the .name/.comment");
	tmp = tmp->next;
	return (tmp);
}
