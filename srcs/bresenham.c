/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:10:32 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/03 16:54:46 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_dx_pos(t_dot p1, t_dot p2, t_data *data)
{
	int	dx;
	int	dy;
	int	p;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p = 2 * dy - dx;
	while (p1.x++ <= p2.x)
	{
		/*if (can_i_print(p1.x, p1.y, data) == 0)
			*/img_pix_put(data, p1.x, p1.y, change_color(p1.z, p2.z));
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
			if (dy >= 0)
				p1.y++;
			else
				p1.y--;
		}
	}
}

void	bresenham_dx_neg(t_dot p1, t_dot p2, t_data *data)
{
	int	dx;
	int	dy;
	int	p;

	dx = p2.x - p1.x;
	dy = p1.y - p2.y;
	p = 2 * dy - dx;
	while (p1.x++ <= p2.x)
	{
		/*if (can_i_print(p1.x, p1.y, data) == 0)
			*/img_pix_put(data, p1.x, p1.y, change_color(p1.z, p2.z));
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
			if (dy < 0)
				p1.y++;
			else
				p1.y--;
		}
	}
}

void	bresenham_dy_pos(t_dot p1, t_dot p2, t_data *data)
{
	int	dx;
	int	dy;
	int	p;

	p1.y -= 2;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p = 2 * dy - dx;
	while (++p1.y <= p2.y)
	{
		/*if (can_i_print(p1.x, p1.y, data) == 0)
			*/img_pix_put(data, p1.x, p1.y, change_color(p1.z, p2.z));
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
			if (dx >= 0)
				p1.x++;
			else
				p1.x--;
		}
	}
}

void	bresenham_dy_neg(t_dot p1, t_dot p2, t_data *data)
{
	int	dx;
	int	dy;
	int	p;

	p1.y -= 2;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p = 2 * dy - dx;
	while (++p1.y <= p2.y)
	{
		/*if (can_i_print(p1.x, p1.y, data) == 0)
			*/img_pix_put(data, p1.x, p1.y, change_color(p1.z, p2.z));
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			p = p + (2 * dy) - (2 * dx);
			if (dx < 0)
				p1.x++;
			else
				p1.x--;
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
