/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:34:23 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/15 19:54:12 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_biggest(int a, int b)
{
	if (a > b)
		return(a);
	else
		return (b);
}

void	trace_line(int *p1, int *p2, t_data *data, int color)
{
	int		dxy[2];
	int		len;
	float	inc[2];
	float	xy[2];
	int		i;
	
	dxy[0] = p2[0] - p1[0];
	dxy[1] = p2[1] - p1[1];
	len = ft_biggest(ft_abs(dxy[0]), ft_abs(dxy[1]));
	inc[0] = dxy[0] / (float)len;
	inc[1] = dxy[1] / (float)len;
	xy[0] = p1[0];
	xy[1] = p1[1];
	i = 0;
	while (i <= len)
	{
		if (can_i_print((int)xy[0], (int)xy[1], data) == 0)
			img_pix_put(data, (int)xy[0], (int)xy[1], color);
		xy[0] += inc[0];
		xy[1] += inc[1];
		i++;
	}
}