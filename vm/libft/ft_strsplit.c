/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:19:08 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/09 14:36:40 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compteur(char const *s, char c)
{
	int		compteur;
	int		i;

	compteur = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		compteur++;
	}
	return (compteur);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fraiche;
	int		i;
	int		j;
	int		begin;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	fraiche = (char**)malloc(sizeof(char*) * (ft_compteur(s, c) + 1));
	if (fraiche == NULL)
		return (NULL);
	while (j++ < ft_compteur(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		begin = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		fraiche[j - 1] = ft_strsub(s, begin, i - begin);
	}
	fraiche[j - 1] = NULL;
	return (fraiche);
}
