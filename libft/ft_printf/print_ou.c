/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:46:20 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/03 11:14:26 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_o(va_list *ap, t_param *param)
{
	int		i;

	i = 0;
	initparamlj(ap, param, 8);
	param->sizestr = ft_strlen(param->str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	if (param->sharp && *(param->str) != '0')
	{
		ft_putchar('0');
		param->number++;
		if (param->precision)
			param->precision--;
	}
	param_precision(param);
	param_zero(param);
	print_arg(param, param->str, i);
	param_minus(param);
	ft_strdel(&param->str);
}

void	print_oup(va_list *ap, t_param *param)
{
	char			*str;
	int				i;

	i = 0;
	param->arglong = va_arg(*ap, unsigned long);
	paramforprecision(param, (int)param->arglong);
	str = ft_ultoabase(param->arglong, 8);
	param->sizestr = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	if (param->sharp && *(str) != '0')
	{
		ft_putchar('0');
		param->number++;
		if (param->precision)
			param->precision--;
	}
	param_precision(param);
	param_zero(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}

void	print_u(va_list *ap, t_param *param)
{
	int		i;

	i = 0;
	initparamlj(ap, param, 10);
	param->sizestr = ft_strlen(param->str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	param_precision(param);
	param_zero(param);
	print_arg(param, param->str, i);
	param_minus(param);
	ft_strdel(&param->str);
}

void	print_uup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	param->arglong = va_arg(*ap, unsigned long);
	str = ft_ultoabase(param->arglong, 10);
	param->sizestr = ft_strlen(str);
	param_width(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}
