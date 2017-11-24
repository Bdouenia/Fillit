/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:50:40 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/24 05:44:36 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
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
	char		c;

	c = 'a';
	add21 = 0;
	nb_tetri = count_tetri(str);
	if (!(locomotive = (t_tetri *)malloc(sizeof(t_tetri))))
		return (locomotive);
	tmp = locomotive;
	while (tmp->next)
	{
		tmp->nb_tetri = nb_tetri;
		creat_tetri(&tmp, ft_strsub(str, add21, 20));
		if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (tmp);
		tmp = tmp->next;
		add21 += 21;
	}
	tmp->next = NULL;
	return (locomotive);
}
