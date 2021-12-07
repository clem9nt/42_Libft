#include <string.h>
#include <stdio.h>

// locates the first occurence of 'char c' in 'char *s' string.
//
// The NULL-term is considered to be a part of the string,
// so if c = '\0' it will locate the NULL-term.
//
// RETURN a pointer to the located character
// or NULL

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i) // not s[i] because segfault /!\
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

int	main(void)
{
	char	str[] = "slaut\0sfsf";
	char	c = 'a';

	printf("lc %p\n", strrchr(str, c));
	printf("ft %p\n", ft_strrchr(str, c));
}
