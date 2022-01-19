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