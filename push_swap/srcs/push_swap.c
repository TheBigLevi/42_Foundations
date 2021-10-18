#include "push_swap.h"

void	usage(int n)
{
	if (n == 1)
		ft_putstr_fd("\n	usage: [1 2 3 ... n]\n\n", 1);
	else if (n == 2)
		ft_putstr_fd("Error\n", 1);
	exit(-1);
}

static void	valid_int(char *argv)
{
	int	i;
	int	len;
	int	sign;

	i = 0;
	sign = 1;
	if (argv[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (argv[i] == '0')
		i++;
	if (sign == -1)
	{
		i--;
		argv[i] = '-';
	}
	len = ft_strlen(argv + i);
	if (len > 11 || (len == 11 && ft_strncmp(argv, "-2147483648", 11) < 0))
		usage(2);
	else if (len > 10 || (len == 10 && ft_strncmp(argv, "2147483647", 10) > 0))
		usage(2);
}

static void	valid_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '\0')
				usage(2);
			j++;
		}
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j] != 1))
				usage(2);
			j++;
		}
		valid_int(argv[i]);
		j = 0;
		i++;
	}
}

int	convert_num(char *num)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (num[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (num[i] == '0')
		i++;
	if (sign == -1)
	{
		i--;
		num[i] = '-';
	}
	sign = ft_atoi(num + i);
	return (sign);
}

int	main(int argc, char *argv[])
{
	t_list *head;

	if (argc == 1)
		usage(1);
	valid_input(argc - 1, argv + 1);
	head = mk_lst(argc -1, argv + 1);
	return (1);
}
