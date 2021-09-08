#include "ft_printf.h"

int	ft_flags(va_list args, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		if (str[i] == '%' && str[i + 1] != '\0')
		{

		}
	}
}
