/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:13:09 by lread             #+#    #+#             */
/*   Updated: 2022/05/11 11:13:20 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdio.h>

typedef enum s_enum {
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}			t_enum;

typedef struct s_data
{
	pthread_mutex_t	printing;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	bool			start;
	long long		start_time;
	bool			dead;
}				t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	pthread_t		monit_id;
	int				num;
	int				times_eaten;
	long long		time_since_eaten;
	bool			ready;
	bool			dead;
}				t_philo;

t_data		*get_data(void);
t_philo		**get_philos(void);
int			ft_atoi(const char *str);
t_philo		*get_philo(int i);
void		is_doing(int num, t_enum action);
long long	get_time(void);
void		*philosopher(void *arg);
void		*monitor(void *arg);
int			create_threads(int i);
void		ft_usleep(int sleep);

#endif
