#include "fractol.h"

int	close_window(int keycode, t_img *img)
{	
	if (keycode == 53)
	{
		mlx_destroy_image(img->mlx_ptr, img->img);
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		exit(1);
	}

	return (0);
}

int winclose(t_img *img)
{
	close_window(53, img);
	return (0);
}

int	mouse_zoom(int keycode, int x, int y)
{
	printf("Keycode: %d\nx: %d\ny: %d\n", keycode, x, y);
	return (0);
}

void	start_hooks(t_img *img_data)
{
	//global = img_data;
	mlx_hook(img_data->win_ptr, 2, 1L<<0, &close_window, img_data);
	mlx_hook(img_data->win_ptr, 17, 1L<<17, &winclose, img_data);
	mlx_mouse_hook(img_data->win_ptr, &mouse_zoom, NULL);
}

// int	handle_no_event(int keycode, t_img *img)
// {
// 	return (0);
// }
