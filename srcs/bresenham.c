/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:10:32 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/22 12:58:55 by mcourtoi         ###   ########.fr       */
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
	p = 2 * dy - dx;
	while (x++ <= p2.x)
	{
		img_pix_put(data, x, y, change_color(p1.z, p2.z));
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
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
	p = 2 * dy - dx;
	while (x++ <= p2.x)
	{
		img_pix_put(data, x, y, change_color(p1.z, p2.z));
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
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
	y = p1.y - 2;
	dx = p2.x - x;
	dy = p2.y - y;
	p = 2 * dy - dx;
	while (++y <= p2.y)
	{
		img_pix_put(data, x, y, change_color(p1.z, p2.z));
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
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
	y = p1.y - 2;
	dx = p1.x - x;
	dy = p2.y - y;
	p = 2 * dy - dx;
	while (++y <= p2.y)
	{
		img_pix_put(data, x, y, change_color(p1.z, p2.z));
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
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
