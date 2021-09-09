#include "ft_printf.h"

static char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

static void	ft_check(t_list *table, char *str)
{
	int	i;

	i = 0;
	if (str[i] == 'c')
		ft_print_char(table);
	else if (str[i] == 's')
		ft_print_str(table);
	else if (str[i] == 'p')
		ft_print_ptr(table);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_print_nbr(table);
	else if (str[i] == 'u')
	else if (str[i] == 'x' || str[i] == 'X')
		ft_print_hex(table);
	else if (str[i])
}

static void	ft_format(t_list *table, char *str)
{
	int	i;

	i = 0;
	while (ft_strchr("cspdiuxX%", str[i]) == 0)
	{
		if (str[i] == '.')
			table->period = 1;
		else if (str[i] == '-')
			table->dash = 1;
		// TODO
		i++;
	}
	ft_check(table, str + i);
}

void	ft_flags(t_list *table, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_format(table->args, str + i);
		}
		i++;
	}
}
