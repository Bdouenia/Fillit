/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:51:14 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/22 17:41:07 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_str(int fd)
{
	int		f;
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	f = read(fd, &c, 1);
	if (f != 1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * 600);
	while (f != '\0')
	{
		str[i] = c;
		i++;
		f = read(fd, &c, 1);
	}
	str[i] = '\0';
	return (str);
}
