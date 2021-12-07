#include <string.h>
#include <stdio.h>

#include <assert.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;

	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (*s2 != c2 && n--)
		s2++;
	if (*s2 == c2 && n)
		return (s2);
	return (0);
}



int	main()
{
	char	*s;
	char	c;
	size_t	n;
	char	*ret0;
	char	*ret1;

	/* s = strgen(rand() % 20); */
	/* c = rand() % 256; */
	/* n = rand() % 20; */

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			printf("----[%i]----\n",i);
			s = "ABCDEFG";
			c = 'A'; // 0
			n = 10;
		}

		if (i == 1)
		{
			printf("----[%i]----\n",i);
			s = ":-^G|";
			c = ':';
			n = 0;
		}

		if (i == 2)
		{
			printf("----[%i]----\n",i);
			s = "ABCDEFG";
			c = '\0';
			n = 10;
		}

		if (i == 3)
		{
			printf("----[%i]----\n",i);
			s = "A\0CDE\0G";
			c = '0';
			n = 5;
		}

		printf("ft_memchr(%s, %c, %lu) => ", s, c, n);
		ret0 = ft_memchr(s, c, n);
		printf("%p '%s'\n", ret0, ret0);

		printf("memchr(%s, %c, %lu) => ", s, c, n);
		ret1 = memchr(s, c, n);
		printf("%p '%s'\n", ret1, ret1);

		printf("\n");
	}

	return (0);
}

