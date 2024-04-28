/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:10:29 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:12:18 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	if (!dstsize)
		return (ft_strlen(src));
	i = -1;
	while (src[++i] && (size_t)i < (dstsize - 1))
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
