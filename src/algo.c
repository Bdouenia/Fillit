/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:17:59 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/24 05:58:40 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char	**ft_convert_letter(char **map, int *tetri->x, int *tetri->y,
		int nb_tetri, int i, int j)
{
	int		a;

	i = 0;
	j = 0;
	a = 0;
	while (a < 4)
		{
			i = tetri->x[a];
			j = tetri->y[a];
			map[j][i] = 'A' + nb_tetri - 1;
			a++;
		}
	}
	return (map);
}

char	**ft_algo(char **map, t_tetri *tetri, size_t size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if(!(map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	map = ft_convert(map, tetri->x, tetri->y, i, j);
	i = tetri->x[ft_max(tetri->x)];
	j = tetri->x[4];
	while (tetri->next)
	{
				
	map = ft_convert_letter(map, tetri->x, tetri->y, i, j);
	tetri = tetri->next;
	}
	return (map);
}
