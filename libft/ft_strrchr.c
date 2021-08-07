#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*chr;

	i = ft_strlen(str) + 1;
	chr = NULL;
	while (i > 0)
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i--;
	}
	return (chr);
}
