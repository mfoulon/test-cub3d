/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:32:10 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:03:52 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	s;

	s = 1;
	n = 0;
	i = 0;
	while (str[i] == 32 || (8 < str[i] && str[i] < 14))
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			s *= -1;
	while (ft_isdigit(str[i]))
		n = n * 10 + str[i++] - 48;
	return (n * s);
}
