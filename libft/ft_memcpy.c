/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:52:29 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:08:34 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = (void *)src;
	i = -1;
	while ((size_t)++i < n)
		d[i] = s[i];
	return (d);
}
