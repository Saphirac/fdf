/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:37 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/06/19 18:30:47 by mcourtoi         ###   ########.fr       */
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

void	fill_map_row(t_map map, int fd)
{
	char	*line;
	char	**split;
	int		i;
	int		j;
	
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		j = -1;
		while (++j < map.max_x)
		{
			map.map[i] = malloc(sizeof(int) * map.max_x);
			// malloc a proteger
			if (split[j])
				map.map[i][j] = ft_atoi(split[j]);
			else
				map.map[i][j] = 0;
		}
		i++;
		ft_free(split);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

t_map parse_map(int fd)
{
	t_map	map;

	map.max_x = size_int(fd, 'x');
	map.max_y = size_int(fd, 'y');
	map.map = malloc(sizeof(int *) * map.max_y);
	if (!map.map)
		exit(EXIT_FAILURE);
	fill_map_row(map, fd);
	return (map);
}

