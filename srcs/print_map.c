/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/14 17:42:50 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	copy_data(t_dot *dot, int *map)
{
	dot->x = map[0];
	dot->y = map[1];
	dot->z = map[2];
}

int	change_color(int z, int z2)
{
	if (z == 0 && z2 == 0)
		return (0xFFFFFFFF);
	else if (z > 0 || z2 > 0)
		return (0xFFFFFFFF);
	else if (z < 0 || z2 < 0)
		return (0xFFFFFFFF);
	else
		return (0xFFFFFFFF);
}

void	print_line(t_map map, t_data *data)
{
	int		i;
	int		j;
	t_dot	p1;
	t_dot	p2;

	i = 0;
	while (i < map.max_y)
	{
		j = -1;
		while (++j < map.max_x - 1)
		{
			copy_data(&p1, map.map[j + (map.max_x * i)]);
			copy_data(&p2, map.map[j + (map.max_x * i) + 1]);
			trace_line(p1, p2, data);
		}
		i++;
	}
}

void	print_columns(t_map map, t_data *data)
{
	int		i;
	int		j;
	t_dot	p1;
	t_dot	p2;

	i = 0;
	j = -1;
	while (++i < map.max_y)
	{
		while (++j < map.max_x * i)
		{
			copy_data(&p1, map.map[j]);
			copy_data(&p2, map.map[j + map.max_x]);
			trace_line(p1, p2, data);
		}
		j--;
	}
}

void	print_points(t_map map, t_data *data)
{
	map.scale = 5;
	apply_scale(&map);
	isometric_transform(&map);
	map.center = 350;
	apply_centering(&map);
	print_line(map, data);
	print_columns(map, data);
}
