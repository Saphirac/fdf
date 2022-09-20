/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:56:47 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/17 13:40:36 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	set_params(char **av)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		exit(0);
	}
	data.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
	data.lenght = 1920;
	data.width = 1080;
	data.addr = mlx_get_data_addr(data.img, &data.bpp,
			&data.line_len, &data.endian);
	data.map = parse_map(av);
	if (!data.map.map)
	{
		free(data.win_ptr);
		exit(EXIT_FAILURE);
	}
	return (data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (check_file(av[1]) == 0)
		{
			data = set_params(av);
			print_points(data.map, &data);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
			ft_free_int(data.map.map, data.map.n_points);
			mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
			mlx_key_hook(data.win_ptr, &handle_input, &data);
			mlx_hook(data.win_ptr, 17, 0L, &handle_cross, &data);
			mlx_mouse_hook(data.win_ptr, &handle_zoom, &data);
			mlx_loop(data.mlx_ptr);
			mlx_destroy_display(data.mlx_ptr);
			free(data.mlx_ptr);
		}
	}
}
