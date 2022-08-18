/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:39:31 by cvidon            #+#    #+#             */
/*   Updated: 2021/11/29 15:39:31 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** @brief      Create a new list.
 **
 ** @param[in]  content the value to initialize the head's content with.
 ** @return     The head of the new list.
 */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first;

	first = malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first->content = content;
	first->next = NULL;
	return (first);
}
