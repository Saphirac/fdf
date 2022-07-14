/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/13 03:37:36 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_points(t_map map, t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	isometric_transform(&map);
	while (i < map.n_points)
	{
		x = map.map[i][0] + 700;
		y = map.map[i][1] + 300;
		if (map.map[i][2] != 0)
			their_mlx_pixel_put(data, x, y, 0x00FF0000);
		else
			their_mlx_pixel_put(data, x, y, 0xFFFFFFFF);		
		printf("x : %d\n y : %d\n", map.map[i][0], map.map[i][1]);
		i++;
	}
}