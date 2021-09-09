#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_list
{
	va_list	args;
	int		count;
	int		space;
	int		period;
	int		sign;
	int		dash;
	int		precision;
	int		width;
}			t_list;

void	ft_flags(t_list *table, char *str);

#endif