/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 19:34:02 by varichar          #+#    #+#             */
/*   Updated: 2018/02/15 21:10:07 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		rev_end(int val, char size)
{
	if (size == 1)
		return (val);
	else if (size == 2)
		return (val >> 8 | val << 8);
	else if (size == 4)
	{
		return (((val >> 24) & 0xff) |\
				((val << 8) & 0xff0000) |\
				((val >> 8) & 0xff00) |\
				((val << 24) & 0xff000000));
	}
	return (0);
}
