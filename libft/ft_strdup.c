/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:24:12 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:11:51 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tab;
	size_t	len;
	int		i;

	len = ft_strlen(s1);
	tab = (char *) ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	i = -1;
	while (s1[++i])
		tab[i] = s1[i];
	return (tab);
}
