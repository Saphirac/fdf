/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:58:32 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/21 20:00:28 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get(char *stash, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		r;

	r = 1;
	while (ft_strchrr(stash, '\n') < 1 && r)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (NULL);
		buf[r] = 0;
		stash = ft_strjoinn(stash, buf);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_stash(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	stash = ft_strndup(stash, i + 1);
	if (!stash)
		return (NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash = ft_get(stash, fd);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	line = ft_line(stash);
	if (!line)
		return (NULL);
	stash = ft_stash(stash);
	if (!stash)
		return (free(line), NULL);
	return (line);
}
