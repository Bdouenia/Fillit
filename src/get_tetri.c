/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:50:40 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/29 04:54:10 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int			count_tetri(char *str)
{
	int		result;

	result = 0;
	while (*str)
	{
		if (*str == '#')
			result++;
		str++;
	}
	return (result / 4);
}
void	creat_tetri(t_tetri **tmp, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

t_tetri		*get_tetri(char *str)
{
	int			nb_tetri;
	t_tetri		*locomotive;
	t_tetri		*tmp;
	int			add21;
	int			c;

	add21 = 0;
	nb_tetri = count_tetri(str);
	c = nb_tetri;
	if (!(locomotive = (t_tetri *)malloc(sizeof(t_tetri))))
		return (locomotive);
	tmp = locomotive;
	while (c > 0)
	{
		tmp->nb_tetri = nb_tetri;
		printf("%s %d | %d\n", "nombre de tetri =", nb_tetri, tmp->nb_tetri);
		creat_tetri(&tmp, ft_strsub(str, 0 + add21, 20));
		if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (tmp);
		tmp = tmp->next;
		add21 += 21;
		c--;
	}
	tmp->next = NULL;
	printf("%s %d\n", "nb_tetri(sortie) =", locomotive->nb_tetri);
	return (locomotive);
}
