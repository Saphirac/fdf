/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:56:47 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/19 03:02:36 by mcourtoi         ###   ########.fr       */
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
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac == 2)
	{
		map = parse_map(av);
		if (!map.map)
			return (1);
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			return (1);
		data.win_ptr = mlx_new_window(data.mlx_ptr, 1600, 900, "FDF");
		if (data.win_ptr == NULL)
		{
			free(data.win_ptr);
			return (1);
		}
		data.img = mlx_new_image(data.mlx_ptr, 1600, 900);
		data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
		
		print_points(map, &data);
		ft_free_int(map.map, map.max_y);
		mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
		mlx_key_hook(data.win_ptr, &handle_input, &data);
		mlx_loop(data.mlx_ptr);

		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
}