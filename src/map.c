/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:59:02 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/29 02:31:41 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char	**creat_map(char **map, size_t size)
{
	unsigned long int y;
	unsigned long int x;

	y = 0;
	x = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (y < size)
	{
		if (!(map[y] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		printf("%s\n", map[y]);
		y++;
		x = 0;
	}
	return (map);
}
void	print_map(char **map)
{
	int i;

	if (map == NULL)
		return (ft_putstr("error"));
	i = 0;
	while (map[i] != 0)
	{
		ft_putendl(map[i]);
		i++;
	}
}

