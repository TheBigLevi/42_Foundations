#include "Philo.h"

static int	usage(int i)
{
	if (i == 0)
		write(1, "Invalid Arguments", 16);
	else if (i == 1)
		write(1, "Philo thread create has failed", 25);
	else if (i == 2)
		write(1, "Mutex init has failed", 22);
	else if (i == 3)
	{
		write(1, "Monit thread create has failed", 31);
	}
	return (1);
}

static void	set_data(char *argv[], int argc)
{
	get_data()->number_of_philo = ft_atoi(argv[0]);
	get_data()->time_to_die = ft_atoi(argv[1]);
	get_data()->time_to_eat = ft_atoi(argv[2]);
	get_data()->time_to_sleep = ft_atoi(argv[3]);
	if (argc == 5)
		get_data()->times_must_eat = ft_atoi(argv[4]);
}



static int	init_data(int argc, char *argv[])
{
	int		i;
	int		err;

	i = 0;
	set_data(argv + 1, argc - 1);
	if (get_data()->number_of_philo == 1)
		return (printf("0ms 1 died"));
	*get_philos() = malloc(sizeof(t_philo) * get_data()->number_of_philo);
	if (*get_philos() == NULL)
		return (1);
	if (pthread_mutex_init(&(get_data()->printing), NULL) != 0)
		return (2);
	while (i < get_data()->number_of_philo)
	{
		err = create_threads(i);
		if (err != 0)
		{
			get_data()->dead = true;
			getPhilo(i - 1)->dead = true;
		}
		i++;
	}
	if (get_data()->dead == true)
		return (3);
	get_data()->start = true;
	get_data()->start_time = get_time();
	return (0);
}

void	exec()
{
	int	i;
	int	philo;

	i = 0;
	philo = get_data()->number_of_philo;
	while (i < philo)
	{
		pthread_join(getPhilo(i)->thread_id, NULL);
		pthread_join(getPhilo(i)->monit_id, NULL);
		i++;
	}
	i = 0;
	while (i < philo)
	{
		pthread_mutex_destroy(&(getPhilo(i)->fork));
		i++;
	}
	pthread_mutex_destroy(&get_data()->printing);
	return;
}

int	main(int argc, char *argv[])
{
	int	error;

	if (argc != 5 && argc != 6)
		return (usage(0));
	error = init_data(argc, argv);
	if (error != 0)
		return (usage(error));
	exec();
	return (0);
}
