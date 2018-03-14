/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:14:59 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:05:17 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fraiche;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	fraiche = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (fraiche == NULL)
		return (NULL);
	fraiche = ft_strcpy(fraiche, s);
	while (fraiche[i] != '\0')
	{
		fraiche[i] = f(fraiche[i]);
		i++;
	}
	return (fraiche);
}
