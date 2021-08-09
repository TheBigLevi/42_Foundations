#include "libft.h"

char	**ft_split(char const *str, char c)
{
	char 	**arr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && j > 0)
		{
			*arr[k] = (char **)malloc(sizeof(*arr));
			arr[k] = (char *)malloc(sizeof(arr) * (j + 1);
			k++;
			j = 0;
			
		} else {
			j++;
		}
		i++;
	}

	return (arr);
}
