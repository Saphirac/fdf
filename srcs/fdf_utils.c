/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:56:52 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/21 19:44:07 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_data *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	**copy_map(int **src, int size)
{
	int	**ret;
	int	i;

	i = 0;
	ret = malloc(sizeof(int *) * size);
	if (!ret)
	{
		ft_free_int(src, size);
		return (NULL);
	}
	while (i < size)
	{
		ret[i] = malloc(sizeof(int) * 3);
		if (!ret[i])
		{
			ft_free_int(ret, (size - i));
			ft_free_int(src, (size));
			return (NULL);
		}
		ret[i][0] = src[i][0];
		ret[i][1] = src[i][1];
		ret[i][2] = src[i][2];
		++i;
	}
	return (ret);
}

void	reprint_modif(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, data->length, data->width);
	if (!data->img)
		ft_error("Mlx error.\n");
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	print_points(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}
