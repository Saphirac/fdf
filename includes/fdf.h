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
# include <math.h>
# include <X11/keysym.h>


typedef struct	s_map {
		int	max_x;
		int	max_y;
		int	**map;
		int	n_points;
		int	scale;
		int	center;
}				t_map;

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		lenght;
	int		width;
	t_map	map;
}				t_data;

void	img_pix_put(t_data *img, int x, int y, int color);

t_map	 parse_map(char **av);
void	ft_free(char **str);
void	isometric_transform(t_map *map);
int		*ft_calloc(int size);
int		ft_smallest(int **tab, int size);
int		is_digit(char *stack);
int		ft_strrlen(char **str);
void	ft_free_int(int **tab, int size);
int		ft_putstr_fd(char *str, int fd);
void	print_points(t_map map, t_data *data);
void	bresenham(int *p1, int *p2, t_data *data);
int		change_color(int z, int z2);
int		check_split(char **split);
t_map	proper_map(t_map map);
void	apply_scale(t_map *map);
void	apply_centering(t_map *map);
int		check_file(char *str);
int		can_i_print(int x, int y, t_data *data);
void	trace_line(int *p1, int *p2, t_data *data, int color);
int		handle_cross(t_data *data);
int		handle_input(int keysym, t_data *data);
int		handle_no_event(void *data);

#endif