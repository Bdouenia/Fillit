/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:28:37 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/22 23:46:55 by bdouenia         ###   ########.fr       */
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

	int		a = 0;
	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	transtet = (get_str(fd));
	printf("%s\n", transtet);
	if (!(check_tetri(transtet)))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	tetri = get_tetri(transtet);
	while (tetri->next)
	{
		a = 0;
		while (a < 4)
		{
			printf("%d %d\n", tetri->x[a], tetri->y[a]);
			a++;
		}
		printf("\n");
		tetri = tetri->next;
	}
	free(transtet);
	solve(tetri);
	free(tetri);
	return (0);
}
