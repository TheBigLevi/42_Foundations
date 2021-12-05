#include "fractol.h"
#include <stdlib.h>

static void	usage(void)
{
	write(1, "usage: ./fractol [jm] [parameters]\n\n\
	j : uses the Julia set with parameters [REAL NUMBER] [IMAGINARY NUMBER]\n\
	m : uses the Mandelbrot set without parameters\n\n", 158);
	exit(-1);
}


		// if (img->endian == 0)
		// 	img->colorRange[color.x] = (0 << 24 | color.r << 16 | color.g << 8 | color.b);
		// else if (img->endian == 1)
		// 	img->colorRange[color.x] = (0 >> 24 | color.r >> 16 | color.g >> 8 | color.b);

static void	create_color_range(t_img *img)
{
	t_rgb color;

	color.x = 0;
	while (color.x < 256)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
		if (color.x < 128)
		{
			color.fraction = scale_between(color.x, 128, 0, 1);
			img->colorRange[color.x] = interpolate(0x0000ff, 0xffffff, color.fraction);
		}
		if (color.x >= 128)
		{
			color.fraction = scale_between(color.x / 2, 128, 0, 1);
			img->colorRange[color.x] = interpolate(0xffffff, 0xff7800, color.fraction);
		}
		color.x += 1;
	}
}

		// if (color.x < 5)
		// {
		// 	color.fraction = scale_between(color.x, 4, 0, 1);
		// 	img->colorRange[color.x] = interpolate(0x0000ff, 0xffffff, color.fraction);
		// }
		// if (color.x >= 5 && color.x < 10)
		// {
		// 	color.fraction = scale_between(color.x - 5, 4, 0, 1);
		// 	img->colorRange[color.x] = interpolate(0xffffff, 0xff7800, color.fraction);
		// }
		// if (color.x >= 10)
		// {
		// 	color.fraction = scale_between(color.x - 10, 245, 0, 1);
		// 	img->colorRange[color.x] = interpolate(0xff7800, 0xff7800, color.fraction);
		// }

// static int	juliaNums(int set, int type)
// {

// }

static void	init_data(t_img *img, t_data *data, char *argv[], int argc)
{
	if (argc == 3 && argv[0][0] == 'j' && argv[0][1] == '\0' )
	{
		if (argv[1][0] >= '0' && argv[1][0] <= '9' && argv[1][1] == '\0')
		{
			data->type = 'j';
			//data->realNum = realNums[argv[1][0]];
			//data->imaginaryNum = juliaNums(ft_atoi(argv[1]), 2);
		}
	}
	else if (argv[0][0] == 'm' && argc == 1)
		data->type = 'm';
	else
		usage();
	img->mlx_ptr = mlx_init();
	img->width = 1920;
	img->height = 1080;
	img->img = mlx_new_image(img->mlx_ptr, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
									&img->line_length, &img->endian);
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->width, img->height, "Fract-ol Generator");
	data->maxIterations = 200;
	data->range = 1;
	create_color_range(img);
}

int	main(int argc, char *argv[])
{
	t_img	img_data;
	t_data	fractol_data;

	if (argc - 1 < 1 || argc - 1 > 3 )
		usage();
	init_data(&img_data, &fractol_data, argv + 1, argc - 1);

	update_img(&img_data, &fractol_data);

	start_hooks(&img_data);
	mlx_loop(img_data.mlx_ptr);
	return(0);
}
