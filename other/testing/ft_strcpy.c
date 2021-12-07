#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	int	offset;

	offset = 0;
	while (*(src + offset))
	{
		*(dst + offset) = *(src + offset);
		offset++;
	}
	*(dst + offset) = '\0';
	return (dst);
}

int	main(void)
{
	char dst[8];
	printf("%s\n", ft_strcpy(dst, "salut"));
	printf("%s\n", strcpy(dst, "salut"));
}
