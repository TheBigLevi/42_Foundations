#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (*a == *b && i < n - 1)
	{
		a++;
		b++;
		i++;
	}
	return (*a - *b);
}
