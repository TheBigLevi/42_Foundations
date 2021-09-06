#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{	
	char	*dest;
	size_t	maxlen;

	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str) || len == 0)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	maxlen = 0;
	if (str[start + maxlen] != '\0' && maxlen < len)
		maxlen++;
	ft_memcpy(dest, str + start, maxlen);
	dest[maxlen] = '\0';
	return (dest);
}
