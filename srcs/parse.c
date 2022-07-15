/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:37 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/14 21:53:47 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (is_digit(split[i]) == 0)
		{	
			ft_free(split);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_x(char *line)
{
	char	**split;
	int		x;
	
	split = ft_split(line, 32);
	if (check_split(split) == 0)
	{
		free(line);
		ft_putstr_fd("Parsing error.\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	x = ft_strrlen(split);
	ft_free(split);
	return (x);
}

int	size_int(int fd, char c)
{
	char		*line;
	int			x;
	static int	y = 0;

	x = 0;
	line = get_next_line(fd);
	while (line)
	{
		y++;
		if (x < get_x(line))
			x = get_x(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (c == 'x')
		return (x);
	else
		return (y);
}

void	fill_subrow(int *map, int size, char **split)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (split[i])
			map[i] = ft_atoi(split[i]);
		else
			map[i] = 0;
		i++;
	}
}

void	fill_map_row(t_map *map, int fd)
{
	char	*line;
	char	**split;
	int		i;
	
	i = -1;
	map->map = malloc(sizeof(int *) * map->max_y);
	if (!map->map)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	while (++i < map->max_y)
	{
		split = ft_split(line, ' ');
		map->map[i] = ft_calloc(map->max_x);
		if (!map->map[i])
			exit(EXIT_FAILURE);
		fill_subrow(map->map[i], map->max_x, split);
		ft_free(split);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	make_positive(t_map *ret)
{
	int	i;
	int	coeff;

	coeff = ft_abs(ft_smallest(ret->map, ret->n_points)) + 1;
	i = -1;
	while (++i < ret->n_points)
	{
		ret->map[i][0] += coeff;
		ret->map[i][1] += coeff;
	}
}

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
				ret->map[index][0] = j * ret->scale;
				ret->map[index][1] = i * ret->scale;
				ret->map[index][2] = map->map[i][j];
				index++;
			}
		}
	}
	//make_positive(ret);
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
		if(!ret.map[i])
			exit(EXIT_FAILURE);
	}
	sub_proper_map(&map, &ret);
	return (ret);
}

t_map	parse_map(char **av)
{
	t_map	map;
	t_map	ret;
	int		fd;

	fd = open(av[1], O_RDWR);
	map.max_x = size_int(fd, 'x');
	map.max_y = size_int(fd, 'y');
	map.scale = 30;
	map.n_points = map.max_y * map.max_x;
	close(fd);
	fd = open(av[1], O_RDWR);
	fill_map_row(&map, fd);
	close(fd);
	ret = proper_map(map);
	if (!ret.map)
		ret.map = NULL;
	ft_free_int(map.map, map.max_y);
	return (ret);
}

