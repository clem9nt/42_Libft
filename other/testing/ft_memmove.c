#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	if (dst == NULL && src == NULL)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d > s)
		while (len--)
			d[len] = s[len];
	else if (d < s)
		while (len--)
			*d++ = *s++;
	return (dst);
}

int	main(void)
{
	for (int i = 0; i <= 6; i++)
	{
		char dest0[] = "salut";
		char dest1[] = "salut";

		char *dst0;
		char *dst1;
		char *src0;
		char *src1;
		int len;

		if (i <= 4)
		{
			printf("%i. NORMAL\n", i);
			dst0 = dest0;
			dst1 = dest1;
			src0 = "foo";
			src1 = "foo";
			len = i;

			printf("   memmove(%s, %s, %i) => ", dst0, src0, len);
			memmove(dst0, src0, len);
			printf("%s\n", dst0);

			printf("ft_memmove(%s, %s, %i) => ", dst1, src1, len);
			ft_memmove(dst1, src1, len);
			printf("%s\n", dst1);
		}

		if (i == 5)
		{
			printf("%i. OVERLAP dst > src\n", i);
			dst0 = &dest0[2];
			dst1 = &dest1[2];
			src0 = &dest0[0];
			src1 = &dest1[0];
			len = 3;

			printf("   memmove(%s, %s, %i) => ", dst0, src0, len);
			memmove(dst0, src0, len);
			printf("%s\n", dst0);

			printf("ft_memmove(%s, %s, %i) => ", dst1, src1, len);
			ft_memmove(dst1, src1, len);
			printf("%s\n", dst1);
		}

		if (i == 6)
		{
			printf("%i. OVERLAP dst < src\n", i);
			dst0 = &dest0[0];
			dst1 = &dest1[0];
			src0 = &dest0[2];
			src1 = &dest1[2];
			len = 3;

			printf("   memmove(%s, %s, %i) => ", dst0, src0, len);
			memmove(dst0, src0, len);
			printf("%s\n", dst0);

			printf("ft_memmove(%s, %s, %i) => ", dst1, src1, len);
			ft_memmove(dst1, src1, len);
			printf("%s\n", dst1);
		}
	}

	// OVERLAP
	/* int d_index = 0; */
	/* int s_index = 2; */

	/* printf("   memmove(%s, %s, %i) => ", &dst0[d_index], &dst0[s_index], len); */
	/* ret0 = memmove(&dst0[d_index], &dst0[s_index], len); */
	/* printf("%s\n", ret0); */

	/* printf("ft_memmove(%s, %s, %i) => ", &dst1[d_index], &dst1[s_index], len); */
	/* ret1 = ft_memmove(&dst1[d_index], &dst1[s_index], len); */
	/* printf("%s\n", ret1); */

	/* return (0); */
}
