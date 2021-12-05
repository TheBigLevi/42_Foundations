#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"

typedef	struct s_rgb
{
	int	x;
	int	r;
	int	g;
	int	b;
	int	fraction;
}				t_rgb;


typedef struct	s_img {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		colorRange[256];
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_data{
	char		type;
	int			subtype;
	double		realNum;
	double		imaginaryNum;
	double		a;
	double		aa;
	double		b;
	double		bb;
	double		range;
	double		ca;
	double		cb;
	int			iterations;
	int			maxIterations;
}				t_data;

int		handle_no_event(int keycode, t_img *img);
int		closeWindow(int keycode, t_img *img);
int		mandlebrot(t_img *img, t_data *data, double x, double y);
void	start_hooks(t_img *img_data);
void	update_img(t_img *img, t_data *data);
double	scale_between(int input, int max_allow, double min, double max);
int		interpolate(int color1, int color2, float fraction);

#endif