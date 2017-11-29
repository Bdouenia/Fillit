/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 01:12:48 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/29 03:05:47 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char	**ft_convert_letter(char ***map, t_tetri *tetri, int count, int i, int j)
{
	int		a;
	int 	x;
	int		y;

	x = 0;
	y = 0;
	a = 0;
	while (a < 4)
	{	
		i = tetri->x[a];
		j = tetri->y[a];
		*map[j][i] = 'A' + count;
		a++;
	}
	while (y < 4)
	{
		printf("%s\n", *map[y]);
		y++;
	}	
	return (*map);
}

int		ft_intlen(int	*un)
{
	int		i;

	i = 0;
	printf("\033[36m   +++++ENTREE_INTLEN+++++\n\033[0m");
	while (*un != 0 || *un == '.')
		i++;

	return (i);
}

int		ft_algo(char ***map, t_tetri *tetri, size_t size)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	j = 0;
	if(!(*map = (char**)malloc(sizeof(char*) * size)))
		return (0);
	printf("\n\033[33m~~~~~~~ENTREE_DU_WHILE~~~~~~~\n\033[0m");
	while (tetri->next && (unsigned long int)ft_intlen(tetri->y) <= ft_strlen(*map[j] - 1))
	{
		i = 0;
		printf("%s %d | %s %d | %s %d\n","count =", count,"i =", i, "j =", j);
		while ((unsigned long int)ft_intlen(tetri->x) <= ft_strlen(*map[j] - 1))
		{
			count++;
			i = i + tetri->x[ft_max(tetri->x)];
			*map = ft_convert_letter(map, tetri, count, i, j);
			tetri = tetri->next;
		}
		while (*map[j][i] != '.' || *map[j][i] == '\0')
		{	
			if (*map[j][i] == '\0')
				j += 1;
			i++;
		}
	}
	if (count == tetri->nb_tetri)
		return (1);
	return (0);
}
