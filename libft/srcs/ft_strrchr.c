#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*chrpos;

	chrpos = NULL;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str == (char)c)
				chrpos = (char *)str;
			str++;
		}
	}
	if (*str == (char)c)
		chrpos = (char *)str;
	return (chrpos);
}
