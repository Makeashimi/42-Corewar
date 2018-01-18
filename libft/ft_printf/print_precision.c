/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:41:36 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/01 18:22:33 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	param_precision(t_param *param)
{
	int		precisioncopy;

	precisioncopy = param->precision;
	if (param->precision)
	{
		if (param->plus && param->minus)
			precisioncopy = param->precision - param->sizestr;
		else if (param->minus && param->width <= param->precision &&
											param->precision >= param->sizestr)
			precisioncopy = param->precision - param->sizestr;
		else if (param->minus)
			precisioncopy = param->width - param->precision - param->sizestr;
		while (precisioncopy > 0)
		{
			ft_putchar('0');
			precisioncopy--;
			param->number++;
		}
	}
}

void	param_precisionstr(t_param *param, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && param->precision > i)
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
}

void	param_precisionwchart(t_param *param, wchar_t *str)
{
	int		i;
	int		stock;
	int		size;

	i = 0;
	stock = param->number;
	size = whatsize(str[i]);
	while (size <= param->precision)
	{
		print_wchart(str[i]);
		stock = param->number + size;
		size = size + whatsize(str[i + 1]);
		i++;
	}
	param->number = stock;
}
