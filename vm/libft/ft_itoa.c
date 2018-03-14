/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:16:45 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/10 16:24:20 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sizehere(int n)
{
	int compteur;

	compteur = 0;
	if (n <= 0)
		compteur++;
	while (n != 0)
	{
		n = n / 10;
		compteur++;
	}
	return (compteur);
}

char		*ft_itoa(int n)
{
	char	*fraiche;
	long	nb;
	int		taille;
	int		i;

	nb = (long)n;
	taille = ft_sizehere(n);
	i = taille - 1;
	fraiche = ft_strnew(taille);
	if (fraiche == NULL)
		return (NULL);
	if (n < 0)
	{
		nb = nb * -1;
		fraiche[0] = '-';
	}
	while (nb >= 10)
	{
		fraiche[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	fraiche[i] = '0' + nb;
	return (fraiche);
}
