/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:59:02 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/23 02:14:12 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

char	**creat_map(char **map, size_t size)
{
	int y;
	int x;

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
			map[x][y] = '.';
			x++;
		}
		map[x][y] = '\0';
		y++;
	}
	map[y] = '\0';
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
