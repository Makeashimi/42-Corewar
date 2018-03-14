/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:26:31 by jcharloi          #+#    #+#             */
/*   Updated: 2018/03/07 20:16:40 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*frais;

	frais = (t_list*)malloc(sizeof(t_list));
	if (frais == NULL)
		return (NULL);
	if (content == NULL)
	{
		frais->content = NULL;
		frais->content_size = 0;
	}
	else
	{
		if (!(frais->content = (void*)malloc(sizeof(char) * content_size)))
			return (NULL);
		ft_memcpy(frais->content, content, content_size);
		frais->content_size = content_size;
	}
	frais->next = NULL;
	return (frais);
}
