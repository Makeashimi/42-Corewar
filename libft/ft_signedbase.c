/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signedbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:37:17 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/19 17:25:46 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sizeint(int n, int base)
{
	int compteur;

	compteur = 0;
	if (n == 0)
		compteur++;
	else if (base == 10 && n < 0)
		compteur++;
	while (n != 0)
	{
		n = n / base;
		compteur++;
	}
	return (compteur);
}

char		*ft_itoabase(int n, int base)
{
	const char	*str = "0123456789abcdef";
	char		*fraiche;
	long		nb;
	int			taille;
	int			i;

	nb = (long)n;
	taille = ft_sizeint(n, base);
	i = taille - 1;
	if (!(fraiche = ft_strnew(taille)))
		return (NULL);
	if (n < 0)
	{
		nb = nb * -1;
		if (base == 10)
			fraiche[0] = '-';
	}
	while (nb >= base)
	{
		fraiche[i] = str[nb % base];
		nb = nb / base;
		i--;
	}
	fraiche[i] = str[nb];
	return (fraiche);
}

static	int	ft_sizelong(long n, unsigned int base)
{
	int compteur;

	compteur = 0;
	if (n == 0)
		compteur++;
	else if (base == 10 && n < 0)
		compteur++;
	while (n != 0)
	{
		n = n / base;
		compteur++;
	}
	return (compteur);
}

char		*ft_ltoabase(long nb, unsigned int base)
{
	const char	*str = "0123456789abcdef";
	char		*fraiche;
	int			taille;
	int			i;

	if (nb == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	taille = ft_sizelong(nb, base);
	i = taille - 1;
	if (!(fraiche = ft_strnew(taille)))
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		if (base == 10)
			fraiche[0] = '-';
	}
	while (nb >= base)
	{
		fraiche[i] = str[nb % base];
		nb = nb / base;
		i--;
	}
	fraiche[i] = str[nb];
	return (fraiche);
}
