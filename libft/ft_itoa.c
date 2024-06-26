/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:55:34 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:06:33 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nbformat(char *tab, unsigned long int nb, size_t i)
{
	while (nb > 0)
	{
		tab[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char				*tab;
	unsigned long int	nb;
	long int			lnb;
	size_t				i;

	lnb = n;
	i = ft_nblen(n);
	tab = (char *) ft_calloc(i + 1, sizeof(char));
	if (!tab)
		return (NULL);
	if (!lnb)
		tab[0] = 48;
	if (lnb < 0)
	{
		nb = lnb * -1;
		tab[0] = 45;
	}
	else
		nb = lnb;
	tab = ft_nbformat(tab, nb, --i);
	return (tab);
}
