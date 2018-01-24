/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:12:48 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/18 18:54:07 by jcharloi         ###   ########.fr       */
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

int		is_all_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_iswhitespace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	parse_asm(t_asm *l_asm)
{
	t_asm	*tmp;
	int		i;

	i = 0;
	tmp = l_asm;
	while (tmp != NULL && is_all_space(tmp->str) == 1)
		tmp = tmp->next;
	while (ft_iswhitespace(tmp->str[i]) == 1)
		i++;
	ft_printf("str : %s\n", tmp->str + i);
	if (ft_strncmp(".name", tmp->str + i, 5) != 0)
		error("Syntax error with the name");
	while (tmp->str[i] != 'e')
		i++;
}