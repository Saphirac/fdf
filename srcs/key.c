/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:03:21 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/17 13:44:54 by mcourtoi         ###   ########.fr       */
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
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img);
	}
	return (0);
}

int	handle_cross(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_zoom(int key, t_data *data)
{
	if (key == 4)
	{
		printf("yo0\n");
		mlx_destroy_image(data->mlx_ptr, data->win_ptr);
		printf("yo1\n");
		data->map.scale += 5;
		printf("yo2\n");
		data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
		printf("yo3\n");
		print_points(data->map, data);
		printf("yo4\n");
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	}
	return (0);
}