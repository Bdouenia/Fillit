/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:15 by bdouenia          #+#    #+#             */
/*   Updated: 2017/11/29 03:46:10 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../libft/libft.h"

typedef struct		s_tetri
{
	int				nb_tetri;
	int				x[4];
	int				y[4];
	struct s_tetri	*next;
}					t_tetri;

int					ft_algo(char ***map, t_tetri *tetri, size_t size);
int					count_tetri(char *str);
void				creat_tetri(t_tetri **tmp, char *str);
t_tetri				*get_tetri(char *str);
char				*get_str(int fd);
int					check_line(char *gone, int j);
int					check_valide(char *gone, int j);
int					check_tetri(char *gone);
char				**creat_map(char **map, size_t size);
void				print_map(char **map);
void				ft_solve(t_tetri *tetri);

#endif
