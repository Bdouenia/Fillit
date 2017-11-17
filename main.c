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

#include "libft/libft.h"

int		main(int ac, char **av)
{
	if (ac < 1)
		return (ft_putstr("usage: fillit source_file");

	if (ft_checkvalide(av[1]) == 0)
		return (ft_pustr("error"));
}
