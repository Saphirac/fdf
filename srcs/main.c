/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:56:47 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/13 03:30:01 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_int(int **tab, int size, int index)
{
	int	i = -1;

	while (++i < size)
		printf("%d ", tab[index][i]);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	map;

	if (ac == 2)
	{
		
		map = parse_map(av);
		if(!map.map)
			return (1);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx,1600, 900, "FDF");
		img.img = mlx_new_image(mlx, 1600, 900);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		print_points(map, &img);
		ft_free_int(map.map, map.max_y);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
}