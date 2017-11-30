/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 01:12:48 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/30 09:22:37 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char	**ft_convert_letter(char **map, t_tetri *tetri, int count, int i, int j)
{
	int		a;
	int 	x;
	int		y;

	x = 0;
	y = 0;
	a = 0;
	printf("\n--------ENTREE_MAP_CONVERT_LETTER-------\n");
	while (a < 4)
	{	
		i = tetri->x[a];
		j = tetri->y[a];
		map[j][i] = 'A' + count;
		a++;
	}
	while (y < 4)
	{
		printf("%s\n", map[y]);
		y++;
	}
	printf("---------------------------------------\n");	
	return (map);
}

int		ft_intlen(int	*un)
{
	unsigned long int		i;
	int						len;

	i = 0;
	len = 0;
	printf("\033[36m   +++++ENTREE_CONDITION+++++\n\033[0m");
	while (i <= 4)
	{
		if (un[i] != un[i - 1])
			len++;
		i++;
	}
	printf("\033[36m           %s %d\n\033[0m", "len =", len);
	return (len);
}

int		ft_space_remain(char **map, int j, size_t size)
{
	unsigned long int		i;

	i = 0;

	printf("\033[36m          %s %zu\n\033[0m", "size =", size);
	while (map[j][i] != '.')
	{
		i++;
		printf(" %s %lu\n", "i2 =", i);
	}
	printf("\033[36m   +++++SORTIE_CONDITION+++++\n\033[0m");
	return (size - i);
}

int		ft_algo(char **map, t_tetri *tetri, size_t size)
{
	int		i;
	int		j;
	int		count;
	int 	a;
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
	while (tetri && ft_intlen(tetri->y) <= ft_space_remain(map, j, size) && a)
	{
		i = 0;
		printf("%s %d | %s %d | %s %d\n","count =", count,"i =", i, "j =", j);
		while (ft_intlen(tetri->x) <= ft_space_remain(map, j, size))
		{
			printf("%s %d | %s %d | %s %d\n","count =", count,"i =", i, "j =", j);
			map = ft_convert_letter(map, tetri, count, i, j);
			tetri = tetri->next;
			while (map[j][i] != '.' && map[j][i] != '\0')
				i++;
			printf("%s %d\n", "i(dansboucle)=", i);
			count++;
		}
		i = 0;
		printf("- - - -entre deux- - - -\n");
		j++;
		while (map[j][i] != '.' || map[j][i] == '\0')
			i++;
		a--;
	}
	if (count == tetri->nb_tetri)
		return (1);
	return (1);
}
