#include "fractol.h"
#include "libft.h"

void	*m_set(t_data img)
{
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	return (img.img);
}