/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullstrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:34:26 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:09:19 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nullstrjoin(char *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s1)
		s1 = (char *) ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	tab = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!tab)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			tab[i] = s1[i];
	j = -1;
	while (s2[++j])
		tab[i++] = s2[j];
	free(s1);
	return (tab);
}
