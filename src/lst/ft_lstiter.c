/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:39:26 by cvidon            #+#    #+#             */
/*   Updated: 2021/11/30 10:17:32 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** @brief      Apply a function to the content of all the element of a list.
 **
 ** @param[out] lst a list.
 ** @param[in]  f a function.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cpy;

	cpy = lst;
	if (!lst || !f)
		return ;
	while (cpy)
	{
		f(cpy->content);
		cpy = cpy->next;
	}
}
