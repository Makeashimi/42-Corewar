/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_after.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:12:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/04 12:05:47 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_type(t_param *param, int c)
{
	const char	*str = "sSpdDioOuUxXcCn%";
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
		{
			param->type = i;
			return (1);
		}
		i++;
	}
	param->type = -1;
	return (0);
}

static void		check_flags(t_param *param, const char *format, int *i)
{
	while (format[*i] == '+' || format[*i] == '-' || format[*i] == '#' ||
			format[*i] == ' ' || format[*i] == '0')
	{
		if (format[*i] == '+')
			param->plus = 1;
		if (format[*i] == '-')
			param->minus = 1;
		if (format[*i] == '#')
			param->sharp = 1;
		if (format[*i] == ' ')
			param->space = 1;
		if (format[*i] == '0')
			param->zero = 1;
		(*i)++;
	}
}

static void		wrong_param(t_param *param, char c)
{
	param->sizestr = 1;
	param_width(param);
	param_zero(param);
	ft_putchar(c);
	param->number++;
	param_minus(param);
}

static void		check_height(t_param *param, const char *format, int *i)
{
	while (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j' ||
				format[*i] == 'z')
	{
		if (format[*i] == 'h')
		{
			if (format[*i + 1] == 'h')
				param->hh = 1;
			else
				param->h = 1;
		}
		if (format[*i] == 'l')
		{
			if (format[*i + 1] == 'l')
				param->ll = 1;
			else
				param->l = 1;
		}
		if (format[*i] == 'j')
			param->j = 1;
		if (format[*i] == 'z')
			param->z = 1;
		(*i)++;
	}
}

void			check_after(t_param *param, const char *format, int *i)
{
	(*i)++;
	check_flags(param, format, i);
	if (ft_isdigit(format[*i]))
	{
		param->width = ft_atoi(&format[*i]);
		(*i) = (*i) + ft_intlen(param->width);
	}
	if (format[*i] == '.')
	{
		param->precisiontest = 1;
		if (ft_isdigit(format[(*i) + 1]))
		{
			param->isprecision = 1;
			param->precision = ft_atoi(&format[(*i) + 1]);
			(*i) = (*i) + ft_intlen(param->precision);
		}
		(*i)++;
	}
	check_height(param, format, i);
	if (check_type(param, format[*i]) == 1)
		return ;
	else if (format[*i] != '\0')
		wrong_param(param, format[*i]);
	else
		(*i)--;
}
