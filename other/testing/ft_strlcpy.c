#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize)
		return (ft_strlen((char *)src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char* )src));
}

int	main(void)
{
	/* int i = 0; */
	/* char  src_list[9][11] = {"1", "",    "Foo", "Foo", "Foo",    "FooFoo", "Foo",    "FooFoo"}; */
	char  src_list[] = "1";
	char *src = malloc (sizeof *src *(strlen(src_list)+1000));
	/* char  src[10] = "1"; */

	int i = 0;
	while(src_list[i])
		*src++ = src_list[i++];
	*src = '\0';


	printf("%s\n", src); //segf

	printf("%s\n", src_list);
	printf("%lu\n", strlen(src_list));
	/* strlcpy(src, src_list, strlen(src) + 1); */
	/* strlcpy(src, src_list[i], strlen(src_list[i]) + 1); */
}
