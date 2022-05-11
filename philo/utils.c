/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:58:57 by lread             #+#    #+#             */
/*   Updated: 2022/05/11 10:59:52 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		val;

	sign = 1;
	i = 0;
	val = 0;
	if (str[i] == '-')
	{
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

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_usec / 1000) + (current_time.tv_sec * 1000));
}

void	ft_usleep(int sleep)
{
	long	cur_time;

	cur_time = get_time();
	while (get_time() - cur_time < sleep)
		usleep(1000);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_data()->start != true)
		;
	ft_usleep(210);
	while (philo->dead != true && get_data()->dead != true)
	{
		if (get_data()->times_must_eat == philo->times_eaten)
			break ;
		if (get_time() - philo->time_since_eaten >= get_data()->time_to_die)
		{
			if (get_data()->dead == true)
				break ;
			pthread_mutex_lock(&get_data()->printing);
			get_data()->dead = true;
			philo->dead = true;
			printf("%lldms %d died\n",
				get_time() - get_data()->start_time, philo->num);
			pthread_mutex_unlock(&get_data()->printing);
			pthread_mutex_unlock(&get_philo(philo->num)->fork);
		}
	}
	return (NULL);
}
