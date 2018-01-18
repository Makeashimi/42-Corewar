/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:49:19 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:03:40 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fraiche;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	fraiche = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (fraiche == NULL)
		return (NULL);
	fraiche = ft_strcpy(fraiche, s);
	while (fraiche[i] != '\0')
	{
		fraiche[i] = f(i, fraiche[i]);
		i++;
	}
	return (fraiche);
}
