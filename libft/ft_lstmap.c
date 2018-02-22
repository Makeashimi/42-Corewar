/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:47:02 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/16 16:47:58 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*suite;
	t_list	*fraiche;

	fraiche = NULL;
	if (lst)
	{
		suite = (*f)(lst);
		fraiche = suite;
		lst = lst->next;
	}
	while (lst)
	{
		suite->next = (*f)(lst);
		suite = suite->next;
		lst = lst->next;
	}
	return (fraiche);
}
