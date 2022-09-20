/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:56:52 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/20 05:50:35 by mcourtoi         ###   ########.fr       */
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
	while (i < size)
	{
		ret[i] = malloc(sizeof(int) * 3);
		ret[i][0] = src[i][0];
		ret[i][1] = src[i][1];
		ret[i][2] = src[i][2];
		++i;
	}
	return (ret);
}
