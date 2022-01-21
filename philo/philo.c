#include "Philo.h"

void	ft_putstr_wtime(const char *str, int num)
{
	int		i;
	char	*nbr;
	char	*index;
	
	i = 0;
	nbr = ft_itoa(get_time());
	while(nbr[i] != '\0')
		i++;
	write(1, nbr, i);
	write(1, "ms ", 3);
	i = 0;
	index = ft_itoa(num);
	while(index[i] != '\0')
		i++;
	write(1, index, 1);
	write(1, " ", 1);
	i = 0;
	while(str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	is_doing(int num, t_enum action)
{
	pthread_mutex_lock(&get_data()->printing);
	if (!get_data()->dead)
	{
		if (action == FORK)
			ft_putstr_wtime("has taken a fork", num);
		else if (action == EATING)
		{
			ft_putstr_wtime("is eating", num);
			usleep(get_data()->time_to_eat * 1000);
		}
		else if (action == SLEEPING)
		{
			ft_putstr_wtime("is sleeping", num);
			usleep(get_data()->time_to_sleep * 1000);
		}
		else if (action == THINKING)
			ft_putstr_wtime("is thinking", num);
	}
	pthread_mutex_unlock(&get_data()->printing);
}

void	try_do(t_philo *philo)
{
	is_doing(philo->num, FORK);
	pthread_mutex_lock(&philo->fork);
	is_doing(philo->num, FORK);
	pthread_mutex_lock(&getPhilo(philo->num)->fork);
	if (get_data()->dead != true)
	{
		is_doing(philo->num, EATING);
		philo->times_eaten += 1;
		philo->time_since_eaten = get_time();
		usleep(get_data()->time_to_eat * 1000);
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&getPhilo(philo->num)->fork);
}

void	*philosopher(void *arg)
{
	t_philo *philo;
	t_philo *philo_in_front;

	philo = (t_philo *)arg;
	philo_in_front = getPhilo(philo->num);
	while (get_data()->start != true);
	if (philo->num % 2 == 1)
		usleep(10);
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
	if (pthread_mutex_init(&(getPhilo(index)->fork), NULL) != 0)
		return (1);
	if (pthread_create(&(getPhilo(index)->thread_id), NULL,
			&philosopher, (void *)getPhilo(index)))
		return (2);
	if (pthread_create(&(getPhilo(index)->monit_id), NULL,
			&monitor, (void *)getPhilo(index)))
		return (3);
	getPhilo(index)->num = index + 1;
	getPhilo(index)->ready = true;
	getPhilo(index)->dead = false;
	getPhilo(index)->times_eaten = 0;
	return (0);
}
