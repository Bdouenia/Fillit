/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:47:32 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/24 05:59:03 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"
#include <stdio.h>

int		calc_size(int	nb)
{
	int 	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

void	solve(t_tetri *tetri)
{
	char	**map;
	size_t	size;
	char	**epilogue;

	
	map = NULL;
	printf("OUIIII0");
	size = calc_size((tetri->nb_tetri) * 4);
	map = creat_map(map, size);
	epilogue = NULL;
	printf("OUIIII1");
	while (!(epilogue = ft_algo(map, tetri, size)))
	{
		size++;
		ft_memdel((void **)map);
		map = creat_map(map, size);
	}
	print_map(epilogue);
}
