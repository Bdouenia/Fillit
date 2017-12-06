/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri_xy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:27:57 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/06 07:34:20 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>
void     move_tmp_x(t_tetri *tetri)
{
	int i;

	i = 0;
	while(i < 4)
	{
		tetri->x[i] += 1;
		i++;
	}
}
void     move_tmp_y(t_tetri *tetri)
{
	int i;

	i = 0;
	while(i < 4)
	{
		tetri->y[i] += 1;
		i++;
	}
}

void     check_tetri_xy(t_tetri *tetri, t_tetri *locomotive, int count, char **map)
{
	int     i;
	int     j;
	int		a;
	int		b;
	t_tetri *tmp;

	a = 0;
	b = 0;
	tmp = locomotive;
	printf ("-~-~-~-~-~ENTREE_CHECK_TETRI-~-~-~-~-~\n");
	i = 0;
	j = 0;
	printf("%s %d\n", "count =", count);
	while (count > 0)
	{
		while(i < 4)
		{
			while(j < 4)
			{
				if ((tetri->x[i] == tmp->x[j] && tetri->y[j] == tmp->y[j]) &&
						map[tetri->y[i]][tetri->x[i]] != '\0')
				{
					a = 0;
					move_tmp_x(tetri);
					b++;
					while (a < 4)
					{
						printf("%d %d\n", tetri->x[a], tetri->y[a]);
						a++;	
					}
				}
				//printf("OK\n");
				if ((map[tetri->y[i]][tetri->x[i]] == '\0' && 
							map[tetri->y[i]][tetri->x[i]] != '.'))
				{
					check_tetri_yx(tetri, map);
					j = 0;
					//printf("infine\n");
					while (j < 4)
					{
						tetri->x[j] -= b;
						j++;
					}
					b = 0;
					j = 0;
				}
				//printf("%d\n", j);
				j++;
			}
			i++;
			j = 0;
		}
		//printf("%s %d\n", "a ===", a);
		//printf("-----\n");
		i = 0;
		j = 0;
		if (a != 0)
			tmp = locomotive;
		else 
		{
			tmp = tmp->next;
			count--;
		}
		a = 0;
	}
}

void     check_tetri_yx(t_tetri *tetri, char **map)
{
	int     i;
	int     j;
	t_tetri *tmp;

	tmp = tetri->next;
	i = 0;
	j = 0;
	while(i < 4)
	{
		while(j < 4)
		{
			if ((map[tetri->y[i]][tetri->x[i]] == '\0' && map[tetri->y[i]][tetri->x[i]] != '.'))
			{
				printf("go tmp_y\n");
				move_tmp_y(tetri);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
