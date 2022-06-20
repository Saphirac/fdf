/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/06/20 18:59:11 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_points(t_map map, t_data *data, int scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.max_y)
	{
		j = -1;
		while (++j < map.max_x)
		{
			if (map.map[i][j] == 0)
				their_mlx_pixel_put(data, (j + 1) * scale, (i + 1) * scale, 0x00FF0000);
			else
				their_mlx_pixel_put(data, (j + 1) * scale, (i + 1) * scale, 0x0000FF00);
		}
		i++;
	}
}