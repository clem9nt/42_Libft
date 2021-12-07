#include <string.h>
#include <stdio.h>

// Compare the null-terminated strings s1 and s2
// Not more than n chars
// Dont compare after '\0'
//
// Return s1 - s2

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// i < (n - 1) parce qu'on compare n charactere et
// si i < n on sortirai de la boucle a n max le return
// comparerait le charactere n + 1


int	main(void)
{

	/* char	s1[] = "d"; */
	/* char	s2[] = "e"; */
	/* int		n = 133; */
	char	s1[] = "^PZ)&^K^YOS]5^D^Fq^H^N:Gld^Dp^LPP%a)^W^X?G";
	char	s2[] = "^N         LnOVz^T";
	int		n = 150;

	printf("ft %i\n", ft_strncmp(s1, s2, n));
	printf("lc %i\n", strncmp(s1, s2, n));
}
