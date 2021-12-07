#include <string.h>
#include <stdio.h>

// locates the first occurence of 'char c' in 'char *s' string.
//
// The NULL-term is considered to be a part of the string,
// so if c = '\0' it will locate the NULL-term.
//
// RETURN a pointer to the located character
// or NULL
//
// --- 0 ---$
// ""^Qf8V^Ve^L?:=^O\%$"
// ""

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

int	main(void)
{
	char	str[] = "[^YSwg+5y^%tj^^*j^YDS*4^Xi^H^[?N^\^Fc^H(^S+ZZ7H=gC^D^^;TCT?2TNC^SjkeqSON^CnA^Q6^^@mYP]";
	char	c = '6';

	printf("%p\n", strchr(str, c));
	printf("%p\n", ft_strchr(str, c));

}
