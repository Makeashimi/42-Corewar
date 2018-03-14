/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:02:43 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/01 17:07:29 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			paramforprecision(t_param *param, int arg)
{
	if (arg == 0 && param->precisiontest == 1 && param->isprecision == 0)
		param->width++;
	if (arg == 0 && param->isprecision == 1 && param->precision == 0)
		param->width++;
}

static void		initparamzelse(va_list *ap, t_param *param, int base)
{
	if (param->z)
	{
		param->size = va_arg(*ap, ssize_t);
		paramforprecision(param, (int)param->size);
		if (param->type == 3 || param->type == 5)
			param->str = ft_ltoabase(param->size, base);
		else
			param->str = ft_ultoabase(param->size, base);
	}
	else if (param->j == 0 && param->l == 0 && param->ll == 0 &&
											param->h == 0 && param->hh == 0)
	{
		if (param->type == 3 || param->type == 5)
		{
			param->arguint = va_arg(*ap, int);
			paramforprecision(param, (int)param->arguint);
			param->str = ft_itoa((int)param->arguint);
		}
		else
		{
			param->arguint = va_arg(*ap, unsigned int);
			paramforprecision(param, (int)param->arguint);
			param->str = ft_uitoabase(param->arguint, base);
		}
	}
}

static void		initparamh(va_list *ap, t_param *param, int base)
{
	if (param->h)
	{
		if (param->type == 3 || param->type == 5)
		{
			param->argshort = va_arg(*ap, int);
			paramforprecision(param, (int)param->argshort);
			param->str = ft_itoabase(param->argshort, base);
		}
		else
		{
			param->argushort = va_arg(*ap, int);
			paramforprecision(param, (int)param->argushort);
			param->str = ft_uitoabase(param->argushort, base);
		}
	}
	initparamzelse(ap, param, base);
}

static void		initparamhh(va_list *ap, t_param *param, int base)
{
	if (param->hh)
	{
		if (param->type == 3 || param->type == 5)
		{
			param->argchar = va_arg(*ap, int);
			paramforprecision(param, (int)param->argchar);
			param->str = ft_itoa((char)param->argchar);
		}
		else
		{
			param->argchar = (unsigned char)va_arg(*ap, int);
			paramforprecision(param, (int)param->argchar);
			param->str = ft_uitoabase(((unsigned char)param->argchar), base);
		}
	}
	else if (param->h)
		initparamh(ap, param, base);
	else
		initparamzelse(ap, param, base);
}

void			initparamlj(va_list *ap, t_param *param, int base)
{
	if (param->l || param->ll)
	{
		if (param->type == 3 || param->type == 5)
		{
			param->arglong = va_arg(*ap, long);
			paramforprecision(param, (int)param->arglong);
			param->str = ft_ltoabase((long)param->arglong, base);
		}
		else
		{
			param->arglong = va_arg(*ap, unsigned long);
			paramforprecision(param, (int)param->arglong);
			param->str = ft_ultoabase(param->arglong, base);
		}
	}
	else if (param->j)
	{
		param->max = va_arg(*ap, uintmax_t);
		paramforprecision(param, (int)param->max);
		if (param->type == 3 || param->type == 5)
			param->str = ft_ltoabase(param->max, base);
		else
			param->str = ft_ultoabase(param->max, base);
	}
	initparamhh(ap, param, base);
}
