#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map {
		int	max_x;
		int	max_y;
		int	**map;
}				t_map;

void	their_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif