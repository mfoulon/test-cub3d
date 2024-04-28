/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:58:55 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:11:11 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(unsigned long long n, int fd)
{
	if (n > 15)
	{
		ft_putptr_fd(n / 16, fd);
		ft_putptr_fd(n % 16, fd);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, fd);
		else
			ft_putchar_fd(n - 10 + 97, fd);
	}
}
