/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lread <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:00:39 by lread             #+#    #+#             */
/*   Updated: 2022/05/11 11:02:43 by lread            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

t_philo	**get_philos(void)
{
	static t_philo	*philos = NULL;

	return (&philos);
}

t_philo	*get_philo(int i)
{
	if (i != get_data()->number_of_philo)
		return (&(*get_philos())[i]);
	return (&(*get_philos())[0]);
}
