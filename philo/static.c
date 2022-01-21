#include "Philo.h"

t_data *get_data(void)
{
	static t_data data;

	return (&data);
}

t_philo **get_philos(void)
{
	static t_philo *philos = NULL;

	return (&philos);
}

t_philo *getPhilo(int i)
{
	if (i != get_data()->number_of_philo)
		return (&(*get_philos())[i]);
	return (&(*get_philos())[0]);
}