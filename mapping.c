/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:50:49 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/22 16:08:32 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		ft_sqrt(int nb)
{
	int sqrt;
	int s;
	int r;

	s = 1;
	r = nb;
	sqrt = 0;
	while (r - s >= 0)
	{
		r = r - s;
		s = s + 2;
		sqrt = sqrt + 1;
	}
	if (r != 0)
		return (sqrt + 1);
	return (sqrt);
}

t_map	*ft_mapnew(int count)
{
	t_map	*elem;
	int		j;
	int		i;

	j = -1;
	if (!(elem = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(elem->map = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (++j < count)
		if (!(elem->map[j] = (char *)malloc(count + 1)))
			return (NULL);
	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
		{
			elem->map[i][j] = '.';
		}
		elem->map[i][j] = '\0';
	}
	elem->map[i] = NULL;
	elem->size = count;
	return (elem);
}

int		ft_fillmapsec(t_map **map, t_tetramino **list, int *i, int *j)
{
	if ((*map)->map[*i + (*list)->p->x[0]][*j + (*list)->p->y[0]] == '.' &&
		(*map)->map[*i + (*list)->p->x[1]][*j + (*list)->p->y[1]] == '.' &&
		(*map)->map[*i + (*list)->p->x[2]][*j + (*list)->p->y[2]] == '.' &&
		(*map)->map[*i + (*list)->p->x[3]][*j + (*list)->p->y[3]] == '.')
	{
		(*map)->map[*i + (*list)->p->x[0]][*j + (*list)->p->y[0]] = (*list)->r;
		(*map)->map[*i + (*list)->p->x[1]][*j + (*list)->p->y[1]] = (*list)->r;
		(*map)->map[*i + (*list)->p->x[2]][*j + (*list)->p->y[2]] = (*list)->r;
		(*map)->map[*i + (*list)->p->x[3]][*j + (*list)->p->y[3]] = (*list)->r;
		if (ft_fillmap(map, (*list)->next) == 1)
		{
			(*map)->map[*i + (*list)->p->x[0]][*j + (*list)->p->y[0]] = '.';
			(*map)->map[*i + (*list)->p->x[1]][*j + (*list)->p->y[1]] = '.';
			(*map)->map[*i + (*list)->p->x[2]][*j + (*list)->p->y[2]] = '.';
			(*map)->map[*i + (*list)->p->x[3]][*j + (*list)->p->y[3]] = '.';
			if (*j + 1 == (*map)->size && ++*i)
				*j = 0;
			else
				*j = *j + 1;
			return (2);
		}
		else
			return (0);
	}
	return (1);
}

int		ft_fillmap(t_map **map, t_tetramino *list)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 0;
	while ((i < (*map)->size || j < (*map)->size) && list)
	{
		if (i + list->p->x[0] >= (*map)->size ||
			i + list->p->x[1] >= (*map)->size ||
			i + list->p->x[2] >= (*map)->size ||
			i + list->p->x[3] >= (*map)->size)
			return (1);
		if ((check = ft_fillmapsec(map, &list, &i, &j)) == 0)
			return (0);
		else if (j + 1 == (*map)->size && check == 1 && ++i)
			j = 0;
		else if (check == 1)
			j++;
	}
	if (!list)
		return (0);
	return (1);
}

t_map	*ft_mapping(t_tetramino **list)
{
	t_map		*map;
	int			count;
	t_tetramino	*temp;
	int			error;

	count = 1;
	temp = (t_tetramino *)malloc(sizeof(t_tetramino));
	temp = *list;
	error = 1;
	while ((temp = temp->next))
		count++;
	temp = *list;
	count = ft_sqrt(count * 4);
	while (error == 1)
	{
		map = (t_map *)malloc(sizeof(t_map));
		map = ft_mapnew(count);
		if ((error = ft_fillmap(&map, *list)) == 0)
			free(map);
		else
			*list = temp;
		count++;
	}
	return (map);
}
