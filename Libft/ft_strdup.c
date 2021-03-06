/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:53:05 by mcourtoi          #+#    #+#             */
/*   Updated: 2021/12/10 05:17:09 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*n;

	i = 0;
	n = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!n)
		return (NULL);
	while (s[i])
	{
		n[i] = s[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
