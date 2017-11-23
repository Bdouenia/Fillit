/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:17:59 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/23 02:28:14 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char	**algo(char **map, t_tetri *tetri, size_t size)
{
	int		i;
	int		j;
	int		a;
	int		letter;

	letter = 'A';
	i = 0;
	j = 0;
	a = 0;
	while (tetri->next)
	{
		while (a < 4)
		{
			i = tetri->x[a];
			j = tetri->y[a];
			map[j][i] = &letter;
			a++;
		}
		j += 1;
		tetri = tetri->next;
		&letter = &letter + 1;
	}
	return (map);
}
