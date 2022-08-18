/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:40:07 by cvidon            #+#    #+#             */
/*   Updated: 2021/12/07 17:43:09 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** @brief      Concatenate two strings into a new string (with malloc).
 **
 ** @param[in]  s1 the first string.
 ** @param[in]  s2 the second string.
 ** @return     A string made of s1 + s2.
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*p3;

	if (!s1 && s2)
		return (ft_strdup (s2));
	if (s1 && !s2)
		return (ft_strdup (s1));
	if (!s1 && !s2)
		return (ft_strdup (""));
	s3 = malloc (sizeof (*s3) * (ft_strlen (s1) + ft_strlen (s2) + 1));
	if (!s3)
		return (NULL);
	p3 = s3;
	while (*s1)
		*p3++ = *s1++;
	while (*s2)
		*p3++ = *s2++;
	return (*p3 = 0, s3);
}

/*
 ** @brief      Concatenate two strings into a new string (with malloc).
 **
 ** @param[in]  s1 the first string (will be free).
 ** @param[in]  s2 the second string.
 ** @return     A string made of s1 + s2.
 */

char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	char	*p1;
	char	*s3;

	p1 = s1;
	s3 = ft_strjoin (s1, s2);
	if (p1)
	{
		free (p1);
		p1 = NULL;
	}
	return (s3);
}

/*
 ** @brief      Concatenate two strings into a new string (with malloc).
 **
 ** @param[in]  s1 the first string.
 ** @param[in]  s2 the second string (will be free).
 ** @return     A string made of s1 + s2.
 */

char	*ft_strjoin_free_s2(char const *s1, char *s2)
{
	char	*p2;
	char	*s3;

	p2 = s2;
	s3 = ft_strjoin (s1, s2);
	if (p2)
	{
		free (p2);
		p2 = NULL;
	}
	return (s3);
}

/*
 ** @brief      Concatenate two strings into a new string (with malloc).
 **
 ** @param[in]  s1 the first string (will be free).
 ** @param[in]  s2 the second string (will be free).
 ** @return     A string made of s1 + s2.
 */

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*p1;
	char	*p2;
	char	*s3;

	p1 = s1;
	p2 = s2;
	s3 = ft_strjoin (s1, s2);
	if (p1)
	{
		free (p1);
		p1 = NULL;
	}
	if (p2)
	{
		free (p2);
		p2 = NULL;
	}
	return (s3);
}
