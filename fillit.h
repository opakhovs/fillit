/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:01:14 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/28 18:12:26 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>

typedef	struct	s_p
{
	int		*x;
	int		*y;
}				t_p;

typedef struct	s_tetramino
{
	t_p					*p;
	char				r;
	struct s_tetramino	*next;
}				t_tetramino;

typedef struct	s_map
{
	char	**map;
	int		size;
}				t_map;

void			ft_printmap(t_map *list);
t_map			*ft_mapping(t_tetramino **list);
int				ft_fillmap(t_map **map, t_tetramino *list);
int				ft_fillmapsec(t_map **map, t_tetramino **list, int *i, int *j);
t_map			*ft_mapnew(int count);
int				ft_sqrt(int nb);
void			ft_freetet(t_tetramino **list);
void			ft_tetadd(t_tetramino **list, t_tetramino *newlist);
t_tetramino		*ft_readfile(int fd);
t_tetramino		*ft_createtetram(char *str, char sym);
t_tetramino		*ft_newtet(void);
int				ft_check_square(char *str, int count);
int				ft_istetramino(char *str);

#endif
