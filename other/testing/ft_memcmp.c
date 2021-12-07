#include <string.h>
#include <assert.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;

	if (n == 0)
		return (0);

	if (*str1 != *str2)
		return (*str1 - *str2);


	while (*str1 == *str2 && n--)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2 && n)
		return (*str1 - *str2);

	return (0);
}

int	main()
{
	// ZERO-LENGTH
	assert(ft_memcmp("", "", 0) == 0);
	assert(ft_memcmp("A", "C", 0) == 0);
	// IDENTICAL
	assert(ft_memcmp("AAAAAAA", "AAAAAAA", 7) == 0);
	// BOUNDARIES
	assert(ft_memcmp("CAAAAAA", "AAAAAAA", 7) > 0);
	assert(ft_memcmp("AAAAAAA", "AAAAAAC", 7) < 0);
	// SPEC
	assert(ft_memcmp("\0\0", "\0È", 2) < 0);
	return (0);
}
