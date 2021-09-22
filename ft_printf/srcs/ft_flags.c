/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:43:04 by lread             #+#    #+#             */
/*   Updated: 2021/09/22 20:43:04 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(t_print *table, const char *str)
{
	if (*str == 'c')
		ft_chr(table);
	else if (*str == 's')
		ft_str(table);
	else if (*str == 'p')
		ft_ptr(table);
	else if (*str == 'd' || *str == 'i')
		ft_signed(table);
	else if (*str == 'u')
		ft_unsigned(table);
	else if (*str == 'x' || *str == 'X')
		ft_hex(table, *str);
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
	}
	str++;
}

void	ft_flags(t_print *table, const char *str)
{
	str++;
	if (ft_strchr("cspdiuxX", *str) == 0)
	{
		ft_putchar_fd(*str, 1);
		table->count += 1;
		str++;
	}
	else
	{
		ft_check(table, str);
	}
}
