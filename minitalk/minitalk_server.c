/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:17:42 by lread             #+#    #+#             */
/*   Updated: 2021/09/30 13:17:44 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"

static void	catch_int(int sig_num)
{
	static uint8_t	byte;
	static uint8_t	count;

	count <<= 1;
	count += 1;
	byte <<= 1;
	if (sig_num == SIGUSR1)
	{
		signal(SIGUSR1, catch_int);
		byte += 1;
	}
	else if (sig_num == SIGUSR2)
		signal(SIGUSR2, catch_int);
	if (count == 0b01111111)
	{
		write(1, &byte, 1);
		if (count == 0b01111111 && byte == 0b00000000)
			write(1, "\n", 1);
		byte = 0;
		count = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd(ft_itoa(pid), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, catch_int);
	signal(SIGUSR2, catch_int);
	while (1)
	{
		pause();
	}
}
