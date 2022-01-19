#include "Philo.h"

// void *func(void *arg)
// {
// 	int *id = (int *)arg;
// 	printf("Hello!! I'm %d", *id);
// 	return NULL;
// }

static void	init_data(int argc, char *argv)
{
	get_data()->number_of_philo = 0;
	get_data()->time_to_die = 0;
	get_data()->time_to_eat = 0;
	get_data()->times_must_eat = 0;

	*get_philos() = (t_philo *)malloc(sizeof(t_philo) * argv[1]);
}

int main(int argc, char *argv[])
{
	init_data(argc, argv);

	// for (int i = 0; i < 3; i++)
	// {
	// 	pthread_t thread_id;
	// 	pthread_create(&thread_id, NULL, func, (void *)&thread_id);
	// 	pthread_join(thread_id, NULL);
	// }

	return (0);
}