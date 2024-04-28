/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:53:11 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:10:58 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong_fd(long long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd(45, fd);
		ft_putlong_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putlong_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
