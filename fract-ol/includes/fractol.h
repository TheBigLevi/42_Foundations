#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"

typedef struct	s_data {
	void	*mlx_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	*j_set(int parameter, t_data img);
void	*m_set(t_data img);

#endif