/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:49:27 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:11:19 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putset(char c, int len)
{
	int	i;

	if (len <= 0)
		return (0);
	i = -1;
	while (++i < len)
		ft_putchar_fd(c, 1);
	return (len);
}
