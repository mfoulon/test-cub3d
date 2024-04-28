/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:18:19 by baptistevie       #+#    #+#             */
/*   Updated: 2024/04/19 16:08:00 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tab;

	tab = (t_list *) ft_calloc(1, sizeof(t_list));
	if (!tab)
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}
