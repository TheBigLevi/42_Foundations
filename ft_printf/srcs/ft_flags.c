#include "ft_printf.h"

static int	ft_check(va_list args, char *str)
{
	if (str[1] == 'c')
		return (1);
}

int	ft_flags(va_list args, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += ft_check(args, str + i);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
		count++;
	}
	return (count);
}
