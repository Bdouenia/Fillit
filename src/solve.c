/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:47:32 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/29 03:17:16 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

size_t		calc_size(int	nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return ((unsigned long int)i);
}

void	ft_solve(t_tetri *tetri)
{
	char	**map;
	size_t	size;
	
	map = NULL;
	printf("\n\033[35m=======ENTREE_DE_FT_SOLVE=======\n\033[0m");
	printf("%s %d\n", "nombre de tetri =", tetri->nb_tetri);
	size = calc_size((tetri->nb_tetri) * 4);
	printf("%s %zu\n", "size =", size);
	printf("\n\033[35m=======ENTREE_DE_CREAT_MAP======\n\033[0m");
	map = creat_map(map, size);
	printf("\n\033[35m=======ENTRE_BACKTRCKING=======\n\033[0m");
	while (!(ft_algo(&map, tetri, size)))
	{
		size++;
		ft_memdel((void **)map);
		map = creat_map(map, size);
	}
	print_map(map);
}
