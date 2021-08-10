#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	while (s1[i + j] != '\0' && ft_strchr(set, s1[i + j]) != 0)
		j++;
	str = ft_substr(s1, i, j + 1);
	return (str);
}
