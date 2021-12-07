#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	offset;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	offset = d_len;
	if (dstsize < d_len)
		return s_len + dstsize;
	if (dstsize > d_len)
		while (*src && offset < dstsize - 1)
			dst[offset++] = *src++;
	dst[offset] = '\0';
	return s_len + d_len;
}

int main()
{
	int  size = 16;
	char first[16] = "This is ";
	char last[] = "a potentially long string";
	int r;

	r = ft_strlcat(first, last, size);

	puts(first);
	printf("Value returned: %d\n",r);
	if(r > size)
		puts("String truncated");
	else
		puts("String was fully copied");

	return(0);
}
