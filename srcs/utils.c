/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:23:11 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/06/19 18:05:57 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_strrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_int(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_putstr_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

int	*ft_calloc(int size)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}

int	ft_smallest(int **tab, int size)
{
	int	n;
	int	i;

	i = 0;
	n = tab[0][0];
	while (i < size)
	{
		if (tab[i][0] < n)
			n = tab[i][0];
		if (tab[i][1] < n)
			n = tab[i][1];
		i++;
	}
	return (n);
}