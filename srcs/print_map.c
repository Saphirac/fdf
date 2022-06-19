/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/06/19 19:28:27 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_points(t_map map, t_data *data, int scale)
{
	int	i;
	int	j;

	i = 0;
	printf("%d\n", map.max_y);
	printf("%d\n", map.max_x);
	while (i < map.max_y)
	{
		j = -1;
		printf("%d\n", i);
		while (++j < map.max_x)
			if (map.map[i][j] == 0)
				their_mlx_pixel_put(data, (j + 1) * scale, (i + 1) * scale, 0x00FF0000);
			else
				their_mlx_pixel_put(data, (j + 1) * scale, (i + 1) * scale, 0x0000FF00);
		i++;
	}
}