/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:43:05 by lread             #+#    #+#             */
/*   Updated: 2021/09/22 20:43:05 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chr(t_print *table)
{
	char	c;

	c = va_arg(table->args, int);
	ft_putchar_fd(c, 1);
	table->count += 1;
}

void	ft_str(t_print *table)
{
	char	*str;

	str = va_arg(table->args, char *);
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		table->count += ft_strlen(str);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		table->count += 6;
	}
}
