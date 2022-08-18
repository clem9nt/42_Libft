/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:39:33 by cvidon            #+#    #+#             */
/*   Updated: 2021/12/03 08:35:15 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** @brief      Scan memory for a character.
 **
 ** "The memchr() function scans the initial n bytes of the memory area pointed
 ** to by s for the first instance of c.  Both c and the bytes of the memory
 ** area pointed to by s are interpreted as unsigned char."
 **
 ** @see        MEMCHR(3) <string.h>
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == s2[i])
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
