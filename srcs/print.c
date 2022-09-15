#include "fdf.h"



void	print_points(t_map map, t_data *data)
{
	map.scale = 30;
	apply_scale(&map);
	isometric_transform(&map);
	map.center = 350;
	apply_centering(&map);
	print_line(map, data);
	print_columns(map, data);
}