#include "libft.h"

char    *ft_strcat(char *dest, const char *src)
{
    int i;
    int j;

    i = 0;
    j = ft_strlen(dest);
    while (src[i] != '\0')
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}