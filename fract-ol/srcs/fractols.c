#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

double	scale_between(int input, int max_allow, double min, double max)
{
	int		min_allow;
	double	scaled_num;
	double	old_range;
	double	new_range;

	min_allow = 0;
	old_range = (max_allow - min_allow);
	new_range = max - min;
	scaled_num = (((input - min) * new_range) / old_range) + min;
	return (scaled_num);
}

int interpolate(int color1, int color2, float fraction)
{
        unsigned char   r1 = (color1 >> 16) & 0xff;
        unsigned char   r2 = (color2 >> 16) & 0xff;
        unsigned char   g1 = (color1 >> 8) & 0xff;
        unsigned char   g2 = (color2 >> 8) & 0xff;
        unsigned char   b1 = color1 & 0xff;
        unsigned char   b2 = color2 & 0xff;

        return (int) ((r2 - r1) * fraction + r1) << 16 |
                (int) ((g2 - g1) * fraction + g1) << 8 |
                (int) ((b2 - b1) * fraction + b1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)dst = color;
}

int	mandlebrot(t_img *img, t_data *data, double x, double y)
{

	data->a = 0;//scale_between(x, img->width, -data->range, data->range);
	data->b = 0;//scale_between(y, img->height, -data->range, data->range);
	data->iterations = 0;
	double	tmp;

	// if (data->type == 'm')
	// {
	// 	data->ca = data->a;
	// 	data->cb = data->b;
	// }
	// else if (data->type == 'j')
	// {
	// 	data->ca = data->realNum;
	// 	data->cb = data->imaginaryNum;
	// }
	while (data->iterations < data->maxIterations)
	{
		tmp = data->a * data->a - data->b * data->b + x;
		data->b = 2 * data->a * data->b + y;
		data->a = tmp;
		if (data->a * data->a + data->b * data->b >= 4)
			break ;
		data->iterations += 1;
	}
	int bright = scale_between(data->iterations, data->maxIterations, 0, 255);
	if (data->iterations == data->maxIterations)
		return 0;
	else
		return img->colorRange[bright];
	
}

void	update_img(t_img *img, t_data *data)
{
	double	x;
	double	y;
	double	xlength;
	double	ylength;
	int i;
	int j;
	int col;

	x = 0;
	y = 0;
	xlength = 2;
	ylength = 1;
	i = 0;
	j = 0;
	while (i < img->width)
	{
		while (j < img->height)
		{
			col = mandlebrot(img, data, x - (xlength / 2) + (xlength / img->width * i), y - (ylength / 2) + (ylength / img->height * j));
			my_mlx_pixel_put(img, i, j, col);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}