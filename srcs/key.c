/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:03:21 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/20 05:49:14 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	else if (keysym == XK_Up)
		data->map.center_y += 30;
	else if (keysym == XK_Down)
		data->map.center_y -= 30;
	else if (keysym == XK_Left)
		data->map.center_x += 60;
	else if (keysym == XK_Right)
		data->map.center_x -= 60;
	else
		return (1);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, data->length, data->width);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	print_points(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
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
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, data->length, data->width);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	print_points(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}
