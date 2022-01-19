#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>

typedef enum s_enum {
	FORK,
	EATING,
	SLEEPING,
	THINKING
}			t_enum;

typedef struct s_data
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	times_must_eat;
}				t_data;


typedef struct s_philo
{
	pthread_t		thread_id;
	pthread_mutex_t	fork;
	int				num;
	bool			ready;
	bool			dead;
	t_data 			*data;
}				t_philo;

t_data *get_data(void);
t_philo **get_philos(void);

#endif
