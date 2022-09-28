/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:56:47 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/28 19:16:26 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_terminate(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_display(data->mlx_ptr);
	ft_free_int(data->map.map, data->map.n_points);
	ft_free_int(data->save, data->map.n_points);
	free(data->mlx_ptr);
}

void	make_map(t_data *data, char **av)
{
	data->map = parse_map(av);
	if (!data->map.map)
	{
		free(data->win_ptr);
		ft_error("Map error.\n");
	}
	data->save = copy_map(data->map.map, data->map.n_points);
	if (!data->save)
	{
		free(data->win_ptr);
		ft_error("Map error.\n");
	}
}

t_data	set_params(char **av)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(0);
	data.length = 1600;
	data.width = 900;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.length, data.width, "FDF");
	if (!data.win_ptr)
		return (free(data.win_ptr), ft_error("Mlx error.\n"), data);
	data.img = mlx_new_image(data.mlx_ptr, data.length, data.width);
	if (!data.img)
		return (free(data.win_ptr), ft_error("Mlx error.\n"), data);
	data.addr = mlx_get_data_addr(data.img, &data.bpp,
			&data.line_len, &data.endian);
	make_map(&data, av);
	if (data.map.n_points == 0)
	{
		mlx_terminate(&data);
		ft_error("Map error.\n");
	}
	data.line_on = 0;
	return (data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("Incorrect arguments.\n");
	if (check_file(av[1]) != 0)
		ft_error("File error.\n");
	data = set_params(av);
	print_points(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_hook(data.win_ptr, 17, 0L, &handle_cross, &data);
	mlx_mouse_hook(data.win_ptr, &handle_zoom, &data);
	mlx_loop(data.mlx_ptr);
	mlx_terminate(&data);
	return (0);
}
