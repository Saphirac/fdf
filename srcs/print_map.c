/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/14 15:38:27 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//p1 : point 1, p2 : point 2
void	bresenham(t_dot p1, t_dot p2, t_data *data)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = p1.x;
	y = p1.y;
	dx = p2.x - x;
	dy = p2.y - y;
	p = 2*dy - dx;
	while (x <= p2.x)
	{
		if (p1.z == 0 && p2.z == 0)
			their_mlx_pixel_put(data, x + 700, y + 300, 0xFFFFFFFF);
		else
			their_mlx_pixel_put(data, x + 700, y + 300, 0x00FF00FF);
		x++;
		if (p < 0)
			p = p + 2*dy;
		else
		{
			p = p + 2*dy - 2*dx;
			y++;
		}	
	}
}

t_dot	copy_data(int *map)
{
	t_dot	dot;
	
	dot.x = map[0];
	dot.y = map[1];
	dot.z = map[2];
	return (dot);
}

void	print_points(t_map map, t_data *data)
{
	int		i;
	int		j;
	t_dot	p1;
	t_dot	p2;

	i = 0;
	isometric_transform(&map);
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
		//printf("px : %d\n py : %d\n", p1.x, p1.y);		
		//printf("x : %d\n y : %d\n", map.map[i][0], map.map[i][1]);
	}

	/*i = 0;
	while (i < map.max_x)
	{
		j = map.max_x * i - 1;
		while (++j < map.max_y - 1)
		{
			p1 = copy_data(map.map[j]);
			p2 = copy_data(map.map[j + (map.max_x * (i + 1))]);
			bresenham(p1, p2, data, 0);
		}
		i++;
		//printf("px : %d\n py : %d\n", p1.x, p1.y);		
		//printf("x : %d\n y : %d\n", map.map[i][0], map.map[i][1]);
	}*/
}