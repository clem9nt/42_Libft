#include "libft.h"
#include <ctype.h>

int	main (void)
{
	int	n;

	n = 'U';
	printf("((%i >= '%i' && %i <= '%i') || (%i >= '%i' && %i <= '%i'))\n", n, 'a', n, 'z', n, 'A', n, 'Z');
	printf("ft_isalpha -> %i (%c)\n", ft_isalpha(n), n);
	printf("   isalpha -> %i (%c)\n", isalpha(n), n);
}
