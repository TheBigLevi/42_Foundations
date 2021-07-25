#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strncpy(char  *dest, const char *src, size_t n);
char    *ft_strcat(char *dest, const char *src);


#endif