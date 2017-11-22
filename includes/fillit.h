/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:15 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/22 17:47:57 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

typedef struct		s_tetri
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_tetri	*next;
}					t_tetri;

int					count_tetri(char *str);
void				creat_tetri(t_tetri **tmp, char *str);
t_tetri				get_tetri(chat *str);
char				*get_str(int fd);
int					check_line(char *gone, int j);
int					check_valide(char *gone, int j);
char				*check_tetri(char *gone);

#endif
