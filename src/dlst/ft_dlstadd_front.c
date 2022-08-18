/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:33:34 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/23 10:19:36 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** @brief      Add an element to the front of a list.
 **
 ** @param[out] lst a list.
 ** @param[in]  new the element to add.
 */

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
