/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <m4rv1n@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:40:12 by cvidon            #+#    #+#             */
/*   Updated: 2021/11/29 15:40:12 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** @brief      Return the length of the given string.
 **
 ** We use pointers instead of counter variable because
 ** it is slightly less power consuming.
 **
 ** @param[in]  str a string.
 ** @return		The string len.
 */

size_t	ft_strlen(char const *str)
{
	char const	*ptr;

	ptr = str;
	while (*ptr)
		++ptr;
	return ((size_t)(ptr - str));
}
