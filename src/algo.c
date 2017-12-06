/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 01:12:48 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/06 07:24:03 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char	**ft_convert_letter(char **map, t_tetri *tetri, int count, size_t size)
{
	int		a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	a = 0;
	printf("\n--------ENTREE_MAP_CONVERT_LETTER-------\n");
	while (map && a < 4 && map[tetri->y[a]][tetri->x[a]] != '\0')
	{	
		i = tetri->x[a];
		j = tetri->y[a];
		map[j][i] = 'A' + count;
		//printf("PASSE\n");
		if (tetri->y[a + 1] < (int)size || tetri->x[a + 1] < (int)size)
		{
		//	printf("REPASSE\n");
			a++;
		}
	}
	printf("a = %d\n", a);
	printf("sort\n");
	if (a != 4)
		return (NULL);
	return (map);
}

int		ft_algo(char **map, t_tetri *tetri, size_t size)
{
	int		i;
	int		j;
	int		count;
	int 	a;
	t_tetri *locomotive;

	locomotive = tetri;
	count = 0;
	i = 0;
	j = 0;
	a = tetri->nb_tetri;
	printf("\n\033[33m~~~~~~~ENTREE_DU_WHILE~~~~~~~\n\033[0m");
	while (j < (int)size)
	{
		while (i < (int)size)
		{	
			ft_putchar(map[j][i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
	i = 0;
	j = 0;
	printf("%s %lu\n", "size =", size);
	while (count <= tetri->nb_tetri)
	{
		printf("%s %d | %s %d\n", "count =", count, "nb_tetri =", tetri->nb_tetri);
		if (count > 0)
			check_tetri_xy(tetri, locomotive, count, map);
		if (!(map = ft_convert_letter(map, tetri, count, size)))
			return (0);
		printf("SORTE\n");
		print_map(map, size);
		count++;
		tetri = tetri->next;
	}
	return (1);
}
