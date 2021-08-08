#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		val;

	sign = 1;
	i = 0;
	val = 0;
	while (ISSPACE(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val * sign);
}