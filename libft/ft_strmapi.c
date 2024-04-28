/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:57:44 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:12:33 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	size_t	len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	tab = (char *) ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	i = -1;
	while ((size_t)++i < len)
		tab[i] = f(i, s[i]);
	return (tab);
}
