/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:28:37 by bdouenia          #+#    #+#             */
/*   Updated: 2017/12/05 02:11:52 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*transtet;
	t_tetri *locomotive;
	t_tetri	*tetri;
	int		a = 0;

	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	transtet = (get_str(fd));
	printf("\033[35m=======MOTIFS=======\n\033[0m");
	printf("%s\n", transtet);
	if (!(check_tetri(transtet)))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	printf("\033[35m=======ENTREE GET_TETRI=======\n\033[0m");
	tetri = get_tetri(transtet);
	locomotive = tetri;
	printf("\n\033[35m=======COORDONEES MAILLONS=======\n\033[0m");
	printf("%s %d\n", "nb_tetri =", tetri->nb_tetri);
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
	tetri = locomotive;
	a = 0;
	free(transtet);
	ft_solve(tetri);
	free(tetri);
	return (0);
}
