/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:52:55 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:12:48 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	if (!(*needle))
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && (size_t) i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && haystack[i + j])
			j++;
		if (!needle[j])
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			return ((char *)haystack + i);
		}
	}
	return (NULL);
}
