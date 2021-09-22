/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:43:05 by lread             #+#    #+#             */
/*   Updated: 2021/09/22 20:43:05 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunsigned(unsigned int n, t_print *table)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10, table);
		table->count += 1;
	}
	ft_putchar_fd((n % 10) + '0', 1);
}

void	ft_signed(t_print *table)
{
	unsigned int	i;
	int				n;

	n = va_arg(table->args, int);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		table->count += 1;
		i = -n;
	}
	else
	{
		i = n;
	}
	ft_putunsigned(i, table);
	table->count += 1;
}

void	ft_unsigned(t_print *table)
{
	unsigned int	n;

	n = va_arg(table->args, unsigned int);
	ft_putunsigned(n, table);
	table->count += 1;
}
