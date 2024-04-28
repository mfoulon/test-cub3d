/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:46:45 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:12:54 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	last = NULL;
	i = -1;
	while (s[++i])
		if (s[i] == (char) c)
			last = (char *) &s[i];
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (last);
}
