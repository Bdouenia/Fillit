/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:17:59 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/24 08:11:49 by dvalenti         ###   ########.fr       */
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

int		ft_intlen(int	*un)
{
	int		i;

	i = 0;
	while (*un != 0 || *un == '.')
		i++;
	return (i);
}

char	**ft_algo(char **map, t_tetri *tetri, size_t size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if(!(map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = tetri->x[ft_max(tetri->x)];
	j = tetri->y[4];
	map = ft_convert(map, tetri->x, tetri->y, i, j);
	tetri = tetri->next;
	while (tetri->next && ft_intlen(tetri->y) <= ft_strlen(map[j] - 1))
	{
		while (ft_intlen(tetri->x) <= ft_strlen(map[j] - 1))
		{
			i = i + tetri->x[ft_max(tetri->x)];
			map = ft_convert_letter(map, tetri->x, tetri->y, i, j);
			tetri = tetri->next;
		}
		if (map[j][i] == '\0')
			j += 1;
		i = ft_intlen(map[y]);	 	
	}
	return (map);
}
