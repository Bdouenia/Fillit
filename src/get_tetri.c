/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:50:40 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/22 17:29:10 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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
	while (str[i])
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = [i % 5];
			(*tmp)->y[j] = [i / 5];
			j++;
		}
	i++;
	}
}

t_tetri		get_tetri(char *str)
{
	int			nb_tetri;
	t_tetri		*locomotive;
	t_tetri		*tmp;

	nb_tetri = count_tetri(str);
	if (!(locomotive = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	while (nb_tetri > 0)
	{
		creat_tetri(tmp, ft_strsub(str, add21, 20)
		if (!(tmp->next = (t_tetri)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
		nb_tetri--;
		add21 += 21;
	}
	tmp->next = NULL;
	return (locomotive);
}
