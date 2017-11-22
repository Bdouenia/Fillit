/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:50:40 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/22 20:58:08 by dvalenti         ###   ########.fr       */
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
		printf("%d\n", i);
		if (str[i] == '#')
		{
			printf("%d\n", j);
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
	printf("%d\n", nb_tetri);
	if (!(locomotive = (t_tetri *)malloc(sizeof(t_tetri))))
		return (locomotive);
	tmp = locomotive;
	printf("malloc locomotive\n");
	while (nb_tetri > 0)
	{
		printf("ok\n");
		tmp->c = c;
		creat_tetri(&tmp, ft_strsub(str, add21, 20));
		printf("ok\n");
		if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (tmp);
		tmp = tmp->next;
		nb_tetri--;
		add21 += 21;
	}
	tmp->next = NULL;
	return (locomotive);
}
