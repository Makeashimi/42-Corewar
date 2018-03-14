/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 18:29:54 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/30 11:16:45 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_x(va_list *ap, t_param *param)
{
	int		i;

	i = 0;
	initparamlj(ap, param, 16);
	param->sizestr = ft_strlen(param->str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	if (param->sharp && *(param->str) != '0')
	{
		ft_putstr("0x");
		param->number = param->number + 2;
	}
	param_precision(param);
	param_zero(param);
	print_arg(param, param->str, i);
	param_minus(param);
	ft_strdel(&param->str);
}

static void		print_xup2(t_param *param)
{
	int		i;

	i = 0;
	if (*(param->str) == '0' && param->precisiontest == 1 &&
												param->isprecision == 0)
	{
		if (param->minus)
			param_minus(param);
		return ;
	}
	if (*(param->str) == '0' && param->isprecision == 1 &&
												param->precision == 0)
	{
		if (param->minus)
			param_minus(param);
		return ;
	}
	while (param->str[i] != '\0')
	{
		ft_putchar(ft_toupper(param->str[i]));
		param->number++;
		i++;
	}
	param_minus(param);
	ft_strdel(&param->str);
}

void			print_xup(va_list *ap, t_param *param)
{
	initparamlj(ap, param, 16);
	param->sizestr = ft_strlen(param->str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	if (param->sharp && *(param->str) != '0')
	{
		ft_putstr("0X");
		param->number = param->number + 2;
	}
	param_precision(param);
	param_zero(param);
	print_xup2(param);
}
