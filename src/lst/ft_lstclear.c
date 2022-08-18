/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:39:23 by cvidon            #+#    #+#             */
/*   Updated: 2022/03/17 12:53:19 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** @brief      Clear a list starting from the given element till the last one.
 **
 ** @param[out] lst a list.
 ** @param[in]  del a function (ie. free).
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr != NULL)
	{
		*lst = (*lst)->next;
		ft_lstdelone(ptr, del);
		ptr = *lst;
	}
}
