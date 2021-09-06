#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && i + j < n - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (n > 0)
		dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j - 1);
}
