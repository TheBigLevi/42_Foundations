/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:09:06 by lread             #+#    #+#             */
/*   Updated: 2022/05/11 11:09:08 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	go_to_sleep(t_enum action)
{
	if (action == EATING)
		ft_usleep(get_data()->time_to_eat);
	else if (action == SLEEPING)
		ft_usleep(get_data()->time_to_sleep);
}

void	is_doing(int num, t_enum action)
{
	long long	time;

	time = get_time() - get_data()->start_time;
	pthread_mutex_lock(&get_data()->printing);
	if (get_data()->dead != true)
	{
		if (action == FORK)
			printf("%lldms %d has taken a fork\n", time, num);
		else if (action == EATING)
			printf("%lldms %d is eating\n", time, num);
		else if (action == SLEEPING)
			printf("%lldms %d is sleeping\n", time, num);
		else if (action == THINKING)
			printf("%lldms %d is thinking\n", time, num);
	}
	pthread_mutex_unlock(&get_data()->printing);
	go_to_sleep(action);
}

void	try_do(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	is_doing(philo->num, FORK);
	pthread_mutex_lock(philo->next_fork);
	is_doing(philo->num, FORK);
	if (get_data()->dead != true)
	{
		philo->time_since_eaten = get_time();
		is_doing(philo->num, EATING);
		philo->times_eaten += 1;
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;
	t_philo	*philo_in_front;

	philo = (t_philo *)arg;
	philo_in_front = get_philo(philo->num);
	philo->next_fork = &(get_philo(philo->num)->fork);
	while (get_data()->start != true)
		;
	philo->time_since_eaten = get_data()->start_time;
	if (philo->num % 2 == 0)
		ft_usleep(get_data()->time_to_eat / 2);
	while (get_data()->dead != true)
	{
		try_do(philo);
		if (get_data()->times_must_eat == philo->times_eaten)
			return (NULL);
		is_doing(philo->num, SLEEPING);
		is_doing(philo->num, THINKING);
	}
	return (NULL);
}

int	create_threads(int index)
{
	get_philo(index)->num = index + 1;
	get_philo(index)->ready = true;
	get_philo(index)->dead = false;
	get_philo(index)->times_eaten = 0;
	if (pthread_mutex_init(&(get_philo(index)->fork), NULL) != 0)
		return (1);
	if (pthread_create(&(get_philo(index)->thread_id), NULL,
			&philosopher, (void *)get_philo(index)))
		return (2);
	if (pthread_create(&(get_philo(index)->monit_id), NULL,
			&monitor, (void *)get_philo(index)))
		return (3);
	return (0);
}
