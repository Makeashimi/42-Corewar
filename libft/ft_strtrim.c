/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:05:47 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 12:46:05 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	if (ft_strlen(s) == i)
		return (ft_strnew(0));
	j = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[j]))
		j--;
	return (ft_strsub(s, i, j + 1 - i));
}
