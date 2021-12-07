#include <string.h>
#include <stdio.h>


// locates the first occurence of 'char *needle' in the 'char *haystack'
// not more than len chars are searched
// chars after \0 are not searched
//
// RETURN
// - haystack if needle is empty
// - NULL if needle is not found
// - otherwise a pointer to the first  char of the first needle occur
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	size_t needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = strlen(needle);
	while (*haystack && len >= needle_len)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}

int	main(void)
{
	/* char	haystack[] = "&vkPG^?^V+"; */
	/* char	needle[] = "k"; */
	/* int	n = 3; */

	/* char	haystack[] = "e "; */
	/* char	needle[] = "e"; */
	/* int	n = 1; */

	/* char	haystack[] = "m^_"; */
	/* char	needle[] = "m^_i"; */
	/* int	n = 7; */

	/* char	haystack[] = "m v,^QW)&^Qd,M"; */
	/* char	needle[] = ",M"; */
	/* int		n = 4; */

	char	haystack[] = "  ";
	char	needle[] = "  ";
	int		n = 1;

	char *ret0;
	char *ret1;
	ret0 = strnstr(haystack, needle, n);
	ret1 = ft_strnstr(haystack, needle, n);
	printf("hay: '%s'\n", haystack);
	printf("nee: '%s'\n", needle);
	printf("len: '%i'\n", n);

	printf("lc %s\n", ret0);
	printf("ft %s\n", ret1);

	return (0);
}
