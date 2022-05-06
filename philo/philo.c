#include "Philo.h"

void	go_to_sleep(t_enum action)
{
	if (action == EATING)
		usleep(get_data()->time_to_eat * 1000);
	else if (action == SLEEPING)
		usleep(get_data()->time_to_sleep * 1000);
}

void	is_doing(int num, t_enum action)
{
	long long	time;

	pthread_mutex_lock(&get_data()->printing);
	if (get_data()->dead != true)
	{
		time = get_time() - get_data()->start_time;
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
		is_doing(philo->num, EATING);
		philo->times_eaten += 1;
		philo->time_since_eaten = get_time();
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
}

void	*philosopher(void *arg)
{
	t_philo *philo;
	t_philo *philo_in_front;

	philo = (t_philo *)arg;
	philo_in_front = getPhilo(philo->num);
	philo->next_fork = &(getPhilo(philo->num)->fork);
	while (get_data()->start != true);
	if (philo->num % 2 == 0) {
		usleep((get_data()->time_to_eat / 2) * 1000); }
	while (get_data()->dead != true)
	{
		try_do(philo);
		is_doing(philo->num, SLEEPING);
		is_doing(philo->num, THINKING);
	}
	return (NULL);
}

int	create_threads(int index)
{
	getPhilo(index)->num = index + 1;
	getPhilo(index)->ready = true;
	getPhilo(index)->dead = false;
	getPhilo(index)->times_eaten = 0;
	getPhilo(index)->time_since_eaten = get_data()->start_time;
	if (pthread_mutex_init(&(getPhilo(index)->fork), NULL) != 0)
		return (1);
	if (pthread_create(&(getPhilo(index)->thread_id), NULL,
			&philosopher, (void *)getPhilo(index)))
		return (2);
	if (pthread_create(&(getPhilo(index)->monit_id), NULL,
			&monitor, (void *)getPhilo(index)))
		return (3);
	return (0);
}
