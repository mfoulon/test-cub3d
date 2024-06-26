/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:27:55 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:10:52 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned int n, int fd, int uppercase)
{
	if (n > 15)
	{
		ft_puthex_fd(n / 16, fd, uppercase);
		ft_puthex_fd(n % 16, fd, uppercase);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, fd);
		else
		{
			if (uppercase)
				ft_putchar_fd(n - 10 + 65, fd);
			else
				ft_putchar_fd(n - 10 + 97, fd);
		}
	}
}
