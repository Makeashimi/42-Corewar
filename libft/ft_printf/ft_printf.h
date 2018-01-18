/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:34:59 by jcharloi          #+#    #+#             */
/*   Updated: 2017/07/24 11:38:47 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <sys/types.h>
# include <ctype.h>
# include <inttypes.h>

typedef	struct	s_param
{
	int					number;
	int					plus;
	int					minus;
	int					sharp;
	int					space;
	int					zero;
	int					width;
	int					precisiontest;
	int					isprecision;
	int					precision;
	int					star;
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					j;
	int					z;
	unsigned long		arglong;
	unsigned int		arguint;
	uintmax_t			max;
	ssize_t				size;
	char				*str;
	unsigned char		argchar;
	short				argshort;
	unsigned short int	argushort;
	int					sizestr;
	int					type;
}				t_param;

typedef	void(*t_arg)(va_list*, t_param*);

int				ft_printf(const char *format, ...);
void			check_after(t_param *param, const char *format, int *i);
void			print_type(t_param *param, va_list *ap);
void			next_param(t_param *param);
void			paramforprecision(t_param *param, int arg);
void			initparamlj(va_list *ap, t_param *param, int base);
void			param_minus(t_param *param);
void			param_plus(t_param *param, int n);
void			param_space(t_param *param);
int				check_widthforsharp(t_param *param);
int				check_forp(t_param *param);
void			param_width(t_param *param);
void			param_widthstr(t_param *param);
void			param_widthwchart(t_param *param, wchar_t *str);
void			param_zero(t_param *param);
void			param_precision(t_param *param);
void			param_precisionstr(t_param *param, char *str);
void			param_precisionwchart(t_param *param, wchar_t *str);
void			print_arg(t_param *param, const char *str, int i);
int				lensharp(t_param *param);
void			print_s(va_list *ap, t_param *param);
void			print_sup(va_list *ap, t_param *param);
void			print_p(va_list *ap, t_param *param);
void			print_d(va_list *ap, t_param *param);
void			print_dup(va_list *ap, t_param *param);
void			print_i(va_list *ap, t_param *param);
void			print_o(va_list *ap, t_param *param);
void			print_oup(va_list *ap, t_param *param);
void			print_u(va_list *ap, t_param *param);
void			print_uup(va_list *ap, t_param *param);
void			print_x(va_list *ap, t_param *param);
void			print_xup(va_list *ap, t_param *param);
void			print_c(va_list *ap, t_param *param);
void			print_cup(va_list *ap, t_param *param);
void			print_pourcent(va_list *ap, t_param *param);
void			print_n(va_list *ap, t_param *param);

#endif
