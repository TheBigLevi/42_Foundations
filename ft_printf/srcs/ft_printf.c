#include "ft_printf.h"

static void	ft_table_init(t_list *table)
{
	table->count = 0;
	table->space = 0;
	table->period = 0;
	table->sign = 0;
	table->dash = 0;
	table->precision = 0;
	table->width = 0;
}

int	ft_printf(const char *str, ...)
{
	t_list	*table;
	int		count;
	int		i;

	table = (t_list *)malloc(sizeof(t_list));
	if (table == NULL)
		return (-1);
	ft_table_init(table);
	va_start(table->args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%')
			ft_flags(table->args, str + i);
		else if (str[i] == '%' && str[i - 1] != '%')
			table->count += write(1, &str[i], 1);
		else
			table->count += write(1, '%', 1);
		i++;
	}
	va_end(table->args);
	count = table->count;
	free(table);
	return (count);
}
