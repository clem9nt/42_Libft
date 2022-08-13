/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:10:52 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/15 12:12:59 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** @brief      Check is the given string has a newline.
 **
 ** @param[in]  str a string.
 ** @return     True or false.
 */

static int	ft_has_nl(char *str)
{
	if (str)
		while (*str)
			if (*str++ == '\n')
				return (1);
	return (0);
}

/*
 ** @brief      Concatenate two strings into a new string (with malloc).
 **
 ** @param[in]  s1 the first string (will be free).
 ** @param[in]  s2 the second string.
 ** @return     A string made of s1 + s2.
 */

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*s3;
	char	*p1;
	char	*p3;

	if (!s1 && s2)
		return (ft_strdup (s2));
	if (s1 && !s2)
		return (ft_strdup (s1));
	if (!s1 && !s2)
		return (ft_strdup (""));
	s3 = malloc (sizeof (char) * (ft_strlen (s1) + ft_strlen (s2) + 1));
	if (!s3)
		return (free (s1), NULL);
	p1 = s1;
	p3 = s3;
	while (*p1)
		*p3++ = *p1++;
	while (*s2)
		*p3++ = *s2++;
	return (*p3 = 0, free (s1), s3);
}

/*
 ** @brief      Extract the first line it finds in temp.
 **
 ** @param[in]  temp can be the next line [ and more ] or NULL.
 ** @return     The next line to be print from temp content.
 */

char	*ft_newline(const char *temp)
{
	size_t	i;

	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	i += (temp[i] == '\n');
	return (ft_substr (temp, 0, i));
}

/*
 ** @brief      Update temp to pass to the next line it contains or NULL if
 **             there is nothing left to read.
 **
 ** @param[in]  temp can be the next line [ and more ] or NULL.
 ** @return     A new temp starting from the next line to read or NULL.
 */

char	*ft_newtemp(char *temp)
{
	char			*new;
	unsigned int	i;

	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
		return (free (temp), NULL);
	i += (temp[i] == '\n');
	new = ft_substr (temp, i, ft_strlen (temp) - i);
	return (free (temp), new);
}

/*
 ** @brief      Get the next line of text available on a file descriptor.
 **
 ** Calling get_next_line in a loop will allow us to read the text available on
 ** the file descriptor one line at a time until the end of it.
 **
 ** A line is defined as a NUL or LF terminated string.
 **
 ** @var        temp can be:
 **              - the next line, if BUFFER_SIZE is smaller than a line.
 **              - the next line and more, if BUFFER_SIZE is bigger than a line.
 **              - NULL if there are no text left to read on the filedes.
 ** @var        line is the last read line.
 ** @var        buf is for read(2) buffer.
 ** @var        rd is for read(2) return value.
 **
 ** @param[in]  fd the file descriptor.
 ** @return     The line that has just been read or NULL.
 */

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*line;
	char		*buf;
	long		rd;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc (sizeof (char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (rd && !ft_has_nl (temp[fd]))
	{
		rd = read (fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (free (buf), NULL);
		buf[rd] = '\0';
		temp[fd] = ft_strjoin (temp[fd], buf);
	}
	free (buf);
	if (!temp[fd])
		return (NULL);
	line = ft_newline (temp[fd]);
	temp[fd] = ft_newtemp (temp[fd]);
	return (line);
}
