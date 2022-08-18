/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:40:05 by cvidon            #+#    #+#             */
/*   Updated: 2021/12/02 18:17:50 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** @brief      Duplicate the given string into a new malloc-ed memory space.
 **
 ** @param[in]  The string to duplicate.
 ** @return     A pointer to the duplication.
 */

char	*ft_strdup(char const *str)
{
	char	*dup;
	char	*ptr;

	if (!str)
		return (NULL);
	dup = malloc (sizeof (*dup) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*str)
		*ptr++ = *str++;
	return (*ptr = 0, dup);
}
