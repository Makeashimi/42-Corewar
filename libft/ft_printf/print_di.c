/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:19:58 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/03 11:19:19 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_d2(t_param *param)
{
	int		i;

	i = 0;
	param_width(param);
	param_plus(param, param->arguint);
	if (param->str[i] == '-')
	{
		ft_putchar('-');
		param->number++;
		i++;
	}
	if (param->zero && param->space)
		param->sizestr++;
	param_precision(param);
	param_zero(param);
	print_arg(param, param->str, i);
	param_minus(param);
	ft_strdel(&param->str);
}

void			print_d(va_list *ap, t_param *param)
{
	int				i;

	i = 0;
	initparamlj(ap, param, 10);
	param->sizestr = ft_strlen(param->str);
	if (param->precision > 0 && param->str[i] == '-')
		param->precision++;
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	if (param->plus && param->minus == 0 && ((int)param->arguint >= 0 ||
															param->zero == 0))
		param->sizestr++;
	if ((int)param->arguint >= 0)
		param_space(param);
	print_d2(param);
}

void			print_dup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;
	long	n;

	i = 0;
	n = va_arg(*ap, long);
	str = ft_ltoabase(n, 10);
	param->sizestr = ft_intlen(n);
	param_plus(param, n);
	if (n >= 0)
		param_space(param);
	param_width(param);
	param_zero(param);
	if (param->plus && n >= 0)
	{
		ft_putchar('+');
		param->number++;
	}
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}

void			print_i(va_list *ap, t_param *param)
{
	print_d(ap, param);
}
