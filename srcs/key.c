/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:03:21 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/21 01:24:25 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

void	handle_translation_angle(int keysym, t_data *data)
{
	if (keysym == XK_Up)
		data->map.center_y += 30;
	else if (keysym == XK_Down)
		data->map.center_y -= 30;
	else if (keysym == XK_Left)
		data->map.center_x += 60;
	else if (keysym == XK_Right)
		data->map.center_x -= 60;
	else if (keysym == XK_F1)
		data->map.angle = 0.523599;
	else if (keysym == XK_F2)
		data->map.angle = 0;
	else if (keysym == XK_F3)
		data->map.angle = 3;
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	else if (keysym != XK_space)
		handle_translation_angle(keysym, data);
	else if (keysym == XK_space)
	{
		if (data->line_on == 0)
			data->line_on = 1;
		else
			data->line_on = 0;
	}
	else
		return (1);
	reprint_modif(data);
	return (0);
}

int	handle_cross(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	handle_zoom(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == 4)
		data->map.scale *= 1.1;
	else if (key == 5)
		data->map.scale *= 0.9;
	else
		return (1);
	reprint_modif(data);
	return (0);
}
