/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:25:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/01 16:44:14 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	param_width(t_param *param)
{
	int		widthcopy;

	widthcopy = param->width;
	if (param->width && param->minus == 0 && param->zero == 0)
	{
		if (param->precision && param->width <= param->precision)
			return ;
		if (param->space)
			widthcopy = param->width - param->sizestr - lensharp(param) - 1;
		if (param->precision == 0 && param->space == 0)
			widthcopy = param->width - param->sizestr - lensharp(param);
		else if (param->precision && param->space == 0)
			widthcopy = param->width - param->precision - param->sizestr -
															lensharp(param);
		while (widthcopy > 0)
		{
			ft_putchar(' ');
			widthcopy--;
			param->number++;
		}
	}
}

void	param_widthstr(t_param *param)
{
	int		widthcopy;

	widthcopy = param->width;
	if (param->width && param->minus == 0 && param->zero == 0)
	{
		if (param->space)
			widthcopy = param->width - param->sizestr - 1;
		if (param->precision && param->sizestr == 0)
			widthcopy = widthcopy - param->sizestr;
		else if (param->precision && param->width >= param->precision &&
											param->sizestr <= param->precision)
			widthcopy = widthcopy - param->precision + param->sizestr;
		else if (param->precision && param->width >= param->precision &&
											param->sizestr >= param->precision)
			widthcopy = widthcopy - param->precision;
		else
			widthcopy = widthcopy - param->sizestr;
		while (widthcopy > 0)
		{
			ft_putchar(' ');
			widthcopy--;
			param->number++;
		}
	}
}

void	param_widthwchart(t_param *param, wchar_t *str)
{
	int		widthcopy;
	int		size;
	int		i;

	i = 0;
	size = whatsize(str[i]);
	if (param->precision)
	{
		while (size + whatsize(str[i + 1]) <= param->precision)
		{
			size = size + whatsize(str[i + 1]);
			i++;
		}
		widthcopy = param->width - size;
	}
	else
		widthcopy = param->width - param->sizestr;
	while (widthcopy > 0 && param->zero == 0 && param->minus == 0)
	{
		ft_putchar(' ');
		widthcopy--;
		param->number++;
	}
}
