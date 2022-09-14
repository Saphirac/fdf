/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:34:23 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/14 17:09:06 by mcourtoi         ###   ########.fr       */
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

void	trace_line(t_dot p1, t_dot p2, t_data *data)
{
	int		dxy[2];
	int		len;
	float	inc[2];
	float	xy[2];
	int		i;
	
	dxy[0] = p2.x - p1.x;
	dxy[1] = p2.y - p1.y;
	len = ft_biggest(ft_abs(dxy[0]), ft_abs(dxy[0]));
	inc[0] = dxy[0] / (float)len;
	inc[1] = dxy[1] / (float)len;
	xy[0] = p1.x;
	xy[1] = p1.y;
	i = 0;
	while (i <= len)
	{
		img_pix_put(data, (int)xy[0], (int)xy[1], 0xFFFFFFFF);
		xy[0] += inc[0];
		xy[1] += inc[1];
		i++;
	}
}