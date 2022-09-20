/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/17 13:32:52 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int	i;
	int	j;

	i = 0;
	while (i < map.max_y)
	{
		j = -1;
		while (++j < map.max_x - 1)
			trace_line(map.map[j + (map.max_x * i)], map.map[j + (map.max_x * i) + 1], data, 0xFFFFFFFF);
		i++;
	}
}

void	print_columns(t_map map, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (++i < map.max_y)
	{
		while (++j < map.max_x * i)
			trace_line(map.map[j], map.map[j + map.max_x], data, 0xFFFFFFFF);
		j--;
	}
}

void	print_points(t_map map, t_data *data)
{
	apply_scale(&map);
	isometric_transform(&map);
	map.center = 350;
	apply_centering(&map);
	print_line(map, data);
	print_columns(map, data);
}
