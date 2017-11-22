/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvalide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:54:43 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/22 17:44:35 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fillit.h"

int		check_line(char *gone, int j)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (gone[i + j] == '#')
		{
			if (gone[i + j + 1] == '#')
				count++;
			if (gone[i + j - 1] == '#')
				count++;
			if (gone[i + j + 5] == '#')
				count++;
			if (gone[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		check_valide(char *gone, int j)
{
	int ht;
	int point;
	int nl;
	int i;

	ht = 0;
	point = 0;
	nl = 0;
	i = 0;
	while (i + j < 20 + j && gone[i + j])
	{
		if (gone[i + j] == '.')
			point++;
		if (gone[i + j] == '\n')
			nl++;
		if (gone[i + j] == '#')
			ht++;
		i++;
	}
	if (ht == 4 && point == 16 && nl == 4)
		return (1);
	return (0);
}

char	*check_tetri(char *gone)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (gone[i + j])
	{
		if(!(check_line(gone, j) && check_valide(gone, j)))
			return (0);
		i = 19;
		if (gone[i + j] == '\n' && gone[i + j + 1] == '\0')
			return (1);
		if (gone[i + j] == '\n' && gone[i + j + 1] == '\n'
		&& (gone[i + j + 2] == '.' || gone[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	retrun (1);
}
