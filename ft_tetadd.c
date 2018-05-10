/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:51:33 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:23:51 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void		ft_tetadd(t_tetramino **list, t_tetramino *newlist)
{
	t_tetramino *head;

	if (!list || !newlist)
		return ;
	if (*list)
	{
		head = *list;
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = newlist;
		*list = head;
	}
	else
		*list = newlist;
}

t_tetramino	*ft_newtet(void)
{
	t_tetramino	*tet;

	tet = (t_tetramino *)malloc(sizeof(t_tetramino));
	tet->p = (t_p *)malloc(sizeof(t_p));
	tet->p->x = (int *)malloc(sizeof(int) * 5);
	tet->p->y = (int *)malloc(sizeof(int) * 5);
	return (tet);
}

void		ft_freetet(t_tetramino **list)
{
	if (!list)
		return ;
	while ((*list))
	{
		free((*list)->p->x);
		free((*list)->p->y);
		(*list)->p->x = NULL;
		(*list)->p->y = NULL;
		free(*list);
		(*list) = (*list)->next;
	}
	free(*list);
	(*list) = NULL;
}
