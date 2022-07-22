/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/21 20:44:24 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	copy_data(int *map)
{
	t_dot	dot;

	dot.x = map[0];
	dot.y = map[1];
	dot.z = map[2];
	return (dot);
}

int	change_color(int z, int z2)
{
	if (z == 0 && z2 == 0)
		return (0xFFFFFFFF);
	else if (z > 0 || z2 > 0)
		return (0x00FF00FF);
	else if (z < 0 || z2 < 0)
		return (0x000000FF);
	else
		return (0x00FFFF00);
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
			p1 = copy_data(map.map[j + (map.max_x * i)]);
			p2 = copy_data(map.map[j + (map.max_x * i) + 1]);
			bresenham(p1, p2, data);
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
			p1 = copy_data(map.map[j]);
			p2 = copy_data(map.map[j + map.max_x]);
			bresenham(p1, p2, data);
		}
		j--;
	}
}

void	print_points(t_map map, t_data *data)
{
	apply_scale(&map);
	isometric_transform(&map);
	apply_centering(&map);
	print_line(map, data);
	print_columns(map, data);
}
