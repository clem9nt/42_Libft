#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

int	main(void)
{
	char dest[20] = "Bit";
	printf("%s\n", ft_strcat(dest, "coin"));
	printf("%s\n", strcat(dest, "coin"));
}
