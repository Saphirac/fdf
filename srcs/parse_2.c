/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:12:25 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/16 01:32:48 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sub_proper_map(t_map *map, t_map *ret)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	while (index < ret->n_points)
	{
		i = -1;
		while (++i < map->max_y)
		{
			j = -1;
			while (++j < map->max_x)
			{
				ret->map[index][0] = j;
				ret->map[index][1] = i;
				ret->map[index][2] = map->map[i][j];
				index++;
			}
		}
	}
}

t_map	proper_map(t_map map)
{
	t_map	ret;
	int		i;

	ret.max_x = map.max_x;
	ret.max_y = map.max_y;
	ret.n_points = map.n_points;
	ret.scale = map.scale;
	ret.map = malloc(sizeof(int *) * (ret.n_points));
	if (!ret.map)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < map.n_points)
	{
		ret.map[i] = malloc(sizeof(int) * 3);
		if (!ret.map[i])
			exit (EXIT_FAILURE);
	}
	sub_proper_map(&map, &ret);
	return (ret);
}
