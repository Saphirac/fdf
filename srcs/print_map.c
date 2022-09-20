/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/21 00:56:31 by mcourtoi         ###   ########.fr       */
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
			trace_line(map.map[j + (map.max_x * i)],
				map.map[j + (map.max_x * i) + 1], data, 0xFFFFFFFF);
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

void	print_only_points(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.n_points)
	{
		if (can_i_print(data->map.map[i][0], data->map.map[i][1], data) == 0)
			img_pix_put(data, data->map.map[i][0],
				data->map.map[i][1], 0xFFFFFFFF);
		++i;
	}
}

void	print_points(t_data *data)
{
	ft_free_int(data->map.map, data->map.n_points);
	data->map.map = copy_map(data->save, data->map.n_points);
	apply_scale(&data->map);
	isometric_transform(&data->map);
	apply_centering(&data->map);
	if (data->line_on == 0)
	{
		print_line(data->map, data);
		print_columns(data->map, data);
	}
	else
		print_only_points(data);
}
