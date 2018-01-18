/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:40:48 by jcharloi          #+#    #+#             */
/*   Updated: 2016/12/05 13:07:00 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fraiche;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	fraiche = (char*)malloc(sizeof(char) * (len + 1));
	if (fraiche == NULL)
		return (NULL);
	ft_strcpy(fraiche, s1);
	ft_strcat(fraiche, s2);
	return (fraiche);
}
