/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:07:53 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/07/22 12:59:45 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_digit(char *stack)
{
	int	i;

	i = -1;
	while (stack[i + 1] == '-' || stack[i + 1] == '+')
		i++;
	while (stack[++i])
		if (!((stack[i] >= '0' && stack[i] <= '9') || stack[i] == '\n'))
			return (0);
	if (i >= 10 && (ft_atoi(stack) > 2147483647
			|| ft_atoi(stack) < -2147483648))
		return (0);
	return (1);
}

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

int	check_file(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'f')
		return (1);
	if (str[i - 2] != 'd')
		return (1);
	if (str[i - 3] != 'f')
		return (1);
	if (str[i - 4] != '.')
		return (1);
	i = open(str, O_RDWR);
	if (i < 0)
	{
		close(i);
		return (1);
	}
	close(i);
	return (0);
}
