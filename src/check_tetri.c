/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvalide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:54:43 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/22 19:31:17 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fillit.h"
#include <stdio.h>

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
	{
		printf("ok1\n");
		return (1);
	}
	printf("nope1\n");
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
	printf("point: %d\n", point);
	printf("ht: %d\n", ht);
	printf("nl: %d\n", nl);
	if (ht == 4 && point == 12 && nl == 4)
	{
		printf("ok2\n");
		return (1);
	}
	printf("nope2\n");
	return (0);
}

int		check_tetri(char *gone)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (gone[i + j])
	{
		if(!(check_line(gone, j) && check_valide(gone, j)))
			return (0);
		printf("ok after check\n");
		i = 19;
		if (gone[i + j] == '\n' && gone[i + j + 1] == '\0')
		{
		printf("1check\n");
			return (1);
		}
		if (gone[i + j] == '\n' && gone[i + j + 1] == '\n'
		&& (gone[i + j + 2] == '.' || gone[i + j + 2] == '#'))
		{
		printf("2check\n");
			j += 21;
		}
		else
			return (0);
		i = 0;
		printf("fin check\n");
	}
	return (1);
}
