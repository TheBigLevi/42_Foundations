#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (str == NULL)
		return (NULL);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		dest[i] = f(i, str[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
