#include <string.h>
#include <assert.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL && src == NULL)
		return (0);

	while (n--)
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return (dst);
}

int	main(void)
{
	char dst0[] = "salut";
	char dst1[] = "salut";
	int len = 3;

	// NORMAL
	char src[] = "foo-bar";

	printf("   memcpy(%s, %s, %i) => ", &dst0[d_index], &dst0[s_index], len);
	char *ret0 = memcpy(&dst0[d_index], &dst0[s_index], len);
	printf("%s\n", ret0);

	printf("ft_memcpy(%s, %s, %i) => ",    &dst1[d_index], &dst1[s_index], len);
	char *ret1 = ft_memcpy(&dst1[d_index], &dst1[s_index], len);
	printf("%s\n", ret1);

	// OVERLAP
	/* int d_index = 0; */
	/* int s_index = 2; */

	/* printf("   memcpy(%s, %s, %i) => ", &dst0[d_index], &dst0[s_index], len); */
	/* char *ret0 = memcpy(&dst0[d_index], &dst0[s_index], len); */
	/* printf("%s\n", ret0); */

	/* printf("ft_memcpy(%s, %s, %i) => ",    &dst1[d_index], &dst1[s_index], len); */
	/* char *ret1 = ft_memcpy(&dst1[d_index], &dst1[s_index], len); */
	/* printf("%s\n", ret1); */

	return (0);
}
