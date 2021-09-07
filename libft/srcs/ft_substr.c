#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{	
	char	*dest;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str) || len == 0)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[start + i] != '\0' && i < len)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
