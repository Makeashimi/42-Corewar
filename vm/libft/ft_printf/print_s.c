/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:19:11 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/30 11:15:26 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_s2(t_param *param, char *str, int test)
{
	int		i;

	i = 0;
	param_widthstr(param);
	param_zero(param);
	if (param->precisiontest == 1 && param->isprecision == 0)
	{
		if (param->minus)
			param_minus(param);
		return ;
	}
	if (param->isprecision == 1 && param->precision == 0)
	{
		if (param->minus)
			param_minus(param);
		return ;
	}
	if (param->precision && param->precision < param->sizestr)
		param_precisionstr(param, str);
	else
		print_arg(param, str, i);
	param_minus(param);
	if (test == 1)
		ft_strdel(&str);
}

void			print_s(va_list *ap, t_param *param)
{
	char	*str;
	int		test;

	test = 0;
	if (param->l)
	{
		print_sup(ap, param);
		return ;
	}
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		test = 1;
	}
	param->sizestr = ft_strlen(str);
	if (param->precisiontest == 1 && param->isprecision == 0)
		param->width = param->width + param->sizestr;
	if (param->isprecision == 1 && param->precision == 0)
		param->width = param->width + param->sizestr;
	print_s2(param, str, test);
}

static void		print_sup3(t_param *param, wchar_t *str)
{
	if (param->precisiontest == 1 && param->isprecision == 0)
	{
		if (param->minus)
			param_minus(param);
		return ;
	}
	if (param->isprecision == 1 && param->precision == 0)
	{
		if (param->minus)
			param_minus(param);
		return ;
	}
	if (param->precision && param->precision < param->sizestr)
		param_precisionwchart(param, str);
	else
	{
		ft_putwchart(str);
		param->number = param->number + param->sizestr;
	}
	param_minus(param);
}

static void		print_sup2(t_param *param, wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		param->sizestr = param->sizestr + whatsize(str[i]);
		i++;
	}
	if (param->precisiontest == 1 && param->isprecision == 0)
		param->width = param->width + param->sizestr;
	if (param->isprecision == 1 && param->precision == 0)
		param->width = param->width + param->sizestr;
	param_widthwchart(param, str);
	param_zero(param);
	print_sup3(param, str);
}

void			print_sup(va_list *ap, t_param *param)
{
	wchar_t		*str;

	str = va_arg(*ap, wchar_t*);
	if (str == NULL)
	{
		if (param->width == 0)
		{
			ft_putstr("(null)");
			param->number = param->number + 6;
		}
		while (param->width)
		{
			ft_putchar(param->zero ? '0' : ' ');
			param->width--;
			param->number++;
		}
		return ;
	}
	print_sup2(param, str);
}
