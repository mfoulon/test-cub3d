/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:13:57 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:08:17 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*str;

	str = (void *)s;
	i = -1;
	while ((size_t)++i < n)
		if (str[i] == (char) c)
			return (&str[i]);
	return (NULL);
}
