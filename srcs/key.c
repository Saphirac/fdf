/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:03:21 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/20 02:57:34 by mcourtoi         ###   ########.fr       */
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
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	handle_cross(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}



int	handle_zoom(int key, t_data *data)
{
	if (key == 4)
	{
		// data->map.scale += 5;
		printf("data: %p\n", data);
			
		//mlx_destroy_image(data->mlx_ptr, data->img);
		// data->img = mlx_new_image(data->mlx_ptr, data->length, data->width);
		// data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
		// print_points(data->map, data);
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	}
	return (0);
}