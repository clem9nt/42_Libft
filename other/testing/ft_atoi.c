#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;

	while (ft_isspace(*str))
		str++;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	nb = 0;
	while (*str && ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
int main(void)
{
	char	*str;

	str = "1";
	printf("'%s'	: ", str);
	printf("'%i'	== ",ft_atoi(str));
	printf("'%i'\n",atoi(str));

	/* str = "777"; */
	/* printf("'%s'	: ", str); */
	/* printf("'%i'		== ",ft_atoi(str));	// 777 */
	/* printf("'%i'\n",atoi(str));		// 777 */

	/* str = " "; */
	/* printf("'%s'	: ", str); */
	/* printf("'%i'		== ",ft_atoi(str));	// -16 */
	/* printf("'%i'\n",atoi(str));		// 0 */

	/* str = " 777"; */
	/* printf("'%s'	: ", str); */
	/* printf("'%i'	== ",ft_atoi(str)); 	// -15223 */
	/* printf("'%i'\n",atoi(str));		// 777 */

	/* 	str = "777 "; */
	/* 	printf("'%s'	: ", str); */
	/* 	printf("'%i'	== ",ft_atoi(str));	// 7754 */
	/* 	printf("'%i'\n",atoi(str));		// 777 */

	/* 	str = " 777 "; */
	/* 	printf("'%s'	: ", str); */
	/* 	printf("'%i'	== ",ft_atoi(str));	// -152246 */
	/* 	printf("'%i'\n",atoi(str));		// 777 */

	/* 	str = "-777"; */
	/* 	printf("'%s'	: ", str); */
	/* 	printf("'%i'	== ",ft_atoi(str));	// -2223 */
	/* 	printf("'%i'\n",atoi(str));		// -777 */

	/* 	str = "2147483647"; */
	/* 	printf("'%s'	: ", str); */
	/* 	printf("'%i'	== ",ft_atoi(str));	// 2147483647 */
	/* 	printf("'%i'\n",atoi(str));		// 2147483647 */

	/* 	str = "-2147483648"; */
	/* 	printf("'%s'	:  ", str); */
	/* 	printf("'%i'	== ",ft_atoi(str));	// -2082712576 */
	/* 	printf("'%i'\n",atoi(str));		// -2147483648 */
}
