#include "Philo.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		val;

	sign = 1;
	i = 0;
	val = 0;

	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val * sign);
}

static unsigned int	ft_numsize(int n)
{
	unsigned int	len;
	unsigned int	num;

	len = 0;
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	num = n;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	len;

	len = ft_numsize(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len + 1] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int get_time()
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	return (current_time.tv_usec / 1000 + current_time.tv_sec * 1000);
}

void	*monitor(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (get_data()->start != true);
	while (philo->dead != true && get_data()->dead != true)
	{
		if (philo->time_since_eaten >= get_data()->time_to_die)
		{
			if (get_data()->dead == true)
				break;
			pthread_mutex_lock(&get_data()->printing);
			get_data()->dead = true;
			philo->dead = true;
			ft_putstr_wtime("died", philo->num);
			pthread_mutex_unlock(&get_data()->printing);
			pthread_mutex_unlock(&getPhilo(philo->num)->fork);
		}
	}
	return (NULL);
}