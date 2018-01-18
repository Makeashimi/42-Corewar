/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:10:59 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/01 14:00:38 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_p(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	param->arglong = va_arg(*ap, unsigned long);
	paramforprecision(param, (int)param->arglong);
	str = ft_ultoabase(param->arglong, 16);
	param->sizestr = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	ft_putstr("0x");
	param->number = param->number + 2;
	param_zero(param);
	param_precision(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}
