/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:28:37 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/22 19:33:24 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*transtet;
	t_tetri	*tetri;

	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	transtet = (get_str(fd));
	if (!(check_tetri(transtet)))
	{
		ft_putstr("error\n");
		return (0);
	}
	printf("no error\n");
	close(fd);
	printf("after close\n");
	tetri = get_tetri(transtet);
	printf("after get\n");
	free(transtet);
//	solve(tetri)
	free(tetri);
	return (0);
}
