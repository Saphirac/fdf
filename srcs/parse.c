/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:37 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/21 19:53:04 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_x(char *line)
{
	char	**split;
	int		x;

	split = ft_split(line, 32);
	if (!split)
		return (-1);
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
		if (x < 0)
			return (free(line), 0);
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
		ft_error("Map error.\n");
	line = get_next_line(fd);
	while (++i < map->max_y)
	{
		split = ft_split(line, ' ');
		map->map[i] = ft_calloc(map->max_x);
		if (!map->map[i])
			ft_error("Map error.\n");
		fill_subrow(map->map[i], map->max_x, split);
		ft_free(split);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

t_map	parse_map(char **av)
{
	t_map	map;
	t_map	ret;
	int		fd;

	fd = open(av[1], O_RDWR);
	if (fd <= 0)
		ft_error("Fd error.\n");
	map.max_x = size_int(fd, 'x');
	map.max_y = size_int(fd, 'y');
	map.n_points = map.max_y * map.max_x;
	close(fd);
	fd = open(av[1], O_RDWR);
	if (fd <= 0)
		ft_error("Fd error.\n");
	fill_map_row(&map, fd);
	close(fd);
	ret = proper_map(map);
	if (!ret.map)
		ret.map = NULL;
	ft_free_int(map.map, map.max_y);
	return (ret);
}
