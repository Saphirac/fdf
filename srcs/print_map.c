/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:36:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/16 00:43:28 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_dx_pos(t_dot p1, t_dot p2, t_data *data)
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
		their_mlx_pixel_put(data, x + 700, y + 300, 0xFFFFFFFF);
		x++;
		if (p < 0)
			p = p + (2*dy);
		else
		{
			p = p + (2*dy) - (2*dx);
			if (dy >= 0)
				y++;
			else 
				y--;
		}
	}
}

void	bresenham_dx_neg(t_dot p1, t_dot p2, t_data *data)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;
	
	x = p1.x;
	y = p1.y;
	dx = p2.x - x;
	dy = p1.y - p2.y;
	p = 2*dy - dx;
	while (x <= p2.x)
	{
		their_mlx_pixel_put(data, x + 700, y + 300, 0xFFFFFFFF);
		x++;
		if (p < 0)
			p = p + (2*dy);
		else
		{
			p = p + (2*dy) - (2*dx);
			if (dy < 0)
				y++;
			else 
				y--;
		}
	}
}

void	bresenham_dy_pos(t_dot p1, t_dot p2, t_data *data)
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
	while (y <= p2.y)
	{
		their_mlx_pixel_put(data, x + 700, y + 300, 0xFFFFFFFF);
		y++;
		if (p < 0)
			p = p + (2*dy);
		else
		{
			p = p + (2*dy) - (2*dx);
			if (dx >= 0)
				x++;
			else 
				x--;
		}
	}
}

void	bresenham_dy_neg(t_dot p1, t_dot p2, t_data *data)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;
	
	x = p1.x;
	y = p1.y;
	dx = p1.x - x;
	dy = p2.y - y;
	p = 2*dy - dx;
	while (y <= p2.y)
	{
		their_mlx_pixel_put(data, x + 700, y + 300, 0xFFFFFFFF);
		y++;
		if (p < 0)
			p = p + (2*dy);
		else
		{
			p = p + (2*dy) - (2*dx);
			if (dx < 0)
				x++;
			else 
				x--;
		}
	}
}

void	bresenham(t_dot p1, t_dot p2, t_data *data)
{
	int	dx;
	int	dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (abs(dx) >= abs(dy))
	{
		if (dx >= 0)
			bresenham_dx_pos(p1, p2, data);
		else
			bresenham_dx_neg(p2, p1, data);
	}
	else 
	{
		if (dy >= 0)
			bresenham_dy_pos(p1, p2, data);
		else
			bresenham_dy_neg(p2, p1, data);
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
	}

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