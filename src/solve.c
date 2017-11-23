/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:47:32 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/23 02:24:01 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

void	solve(t_tetri *tetri)
{
	char	**map;
	size_t	size;
	char	*epilogue;

	size = 2;
	map = NULL;
	map = creat_map(map, size);
	epilogue = NULL;
	while (!(epilogue = algo(map, tetri, size)))
	{
		size++;
		ft_memdel((void **)map);
		map = tetri_map_new(map, size);
	}
	print_map(epilogue);
}
