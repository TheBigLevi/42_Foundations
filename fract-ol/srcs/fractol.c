#include "fractol.h"
#include "libft.h"

static void	usage(void)
{
	ft_putstr_fd("\n\
usage: ./fractol [-jm] [parameter]\n\n\
	j : uses the Julia set with parameters\n\
	m : uses the Mandelbrot set without parameters\n\n\
	SOME PARAMETERS...\n\n", 1);
	exit(-1);
}

static int	get_type2(char *str)
{
	if (str[0] != 'm' && str[1] != '\0')
	{
		ft_putstr_fd("\nInvalid Fractol Types", 1);
		usage();
	}
	return (2);
}

static int	get_type(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 3 && argv[1][0] == 'j' && argv[1][1] == '\0')
	{
		if (argv[2][i] == '-')
			i++;
		while (1)
		{
			if (ft_isdigit(argv[2][i]) == 0)
			{
				ft_putstr_fd("\nInvalid Parameter", 1);
				usage();
			}
			i++;
			if (argv[2][i] == '\0')
				break ;
		}
		return (1);
	}
	return (get_type2(argv[1]));
}

static void	*set_type(int type, int parameter, t_data img)
{
	
	if (type == 1)
		return (j_set(parameter, img));
	else if (type == 2)
		return (m_set(img));
	else if (type == 3)
		return (NULL);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	void	*win_ptr;
	int		type;
	int		param;
	t_data	img;

	if (argc > 3 || argc < 2)
		usage();
	img.mlx_ptr = mlx_init();
	img.img = mlx_new_image(img.mlx_ptr, 1920, 1080);
	type = get_type(argc, argv);
	param = 0;
	if (type == 1)
		param = ft_atoi(argv[2]);
	set_type(type, param, img);
	win_ptr = mlx_new_window(img.mlx_ptr, 1920, 1080, "Fract-ol Generator");
	mlx_put_image_to_window(img.mlx_ptr, win_ptr, img.img, 0,1);
	mlx_loop(img.mlx_ptr);
}
