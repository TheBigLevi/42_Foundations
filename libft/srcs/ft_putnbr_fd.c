/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:03:44 by lread             #+#    #+#             */
/*   Updated: 2021/09/07 14:03:44 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
	}
	else
	{
		num = n;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((num % 10) + '0', fd);
}
