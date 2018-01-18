/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:42:48 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/03 11:24:08 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

void			print_c(va_list *ap, t_param *param)
{
	char	c;

	if (param->l)
	{
		print_cup(ap, param);
		return ;
	}
	c = va_arg(*ap, int);
	param->sizestr = 1;
	param_width(param);
	param_zero(param);
	ft_putchar(c);
	param->number++;
	param_minus(param);
}

void			print_cup(va_list *ap, t_param *param)
{
	wchar_t		c;

	c = va_arg(*ap, wchar_t);
	param->sizestr = whatsize(c);
	param_width(param);
	param_zero(param);
	print_wchart(c);
	param->number = param->number + param->sizestr;
	param_minus(param);
}
