/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:28:37 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/17 23:58:18 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*transtet
	t_tet	*tetri

	if (ac < 1)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	transtet = (get_str(fd))
	if (!(check_tet(transtet)))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	tetri = (get_tetri(transtet));
	solve(tetri)
	free(transtet);
	free(tetri);
	return (0);
}
