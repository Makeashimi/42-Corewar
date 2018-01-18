/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:27:41 by jcharloi          #+#    #+#             */
/*   Updated: 2017/11/24 19:41:51 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fraiche;

	if (s == NULL)
		return (NULL);
	fraiche = ft_strnew(len);
	if (fraiche == NULL)
		return (NULL);
	fraiche = ft_strncpy(fraiche, s + start, len);
	return (fraiche);
}
