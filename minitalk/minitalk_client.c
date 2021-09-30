/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:17:52 by lread             #+#    #+#             */
/*   Updated: 2021/09/30 13:17:56 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"

static void	pid_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

static void	send_byte(pid_t pid, unsigned char c)
{
	uint8_t	byte;

	byte = 1 << 6;
	while (byte != 0)
	{
		if (byte & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				pid_error("Proccess ID Invalid!\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				pid_error("Proccess ID Invalid!\n");
		}
		byte >>= 1;
		usleep(100);
	}
}

static void	message_handler(char *pid_str, char *msg)
{
	pid_t	pid;
	int		i;

	pid = ft_atoi(pid_str);
	i = 0;
	while (msg[i] != '\0')
	{
		send_byte(pid, msg[i]);
		i++;
	}
	send_byte(pid, msg[i]);
}

static void	bad_input(void)
{
	write(1, "usage: ./client [servers-pid] [message]\n", 42);
	exit(0);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		bad_input();
	message_handler(argv[1], argv[2]);
	return (1);
}
