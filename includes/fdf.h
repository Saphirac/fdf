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

t_map	 parse_map(char **av);
void	ft_free(char **str);
int		*ft_calloc(int size);
int		is_digit(char *stack);
int		ft_strrlen(char **str);
void	ft_free_int(int **tab, int size);
int		ft_putstr_fd(char *str, int fd);
void	print_points(t_map map, t_data *data, int scale);

#endif