/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:58:04 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/28 17:03:22 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_istetramino(char *str)
{
	int		i;
	int		blocks;

	i = 0;
	blocks = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (((i - 1) >= 0 && str[i - 1] == '#'))
				blocks++;
			if (((i - 5) >= 0 && str[i - 5] == '#'))
				blocks++;
			if (((i + 1) < 20 && str[i + 1] == '#'))
				blocks++;
			if (((i + 5) < 20 && str[i + 5] == '#'))
				blocks++;
		}
		i++;
	}
	if ((blocks == 6 || blocks == 8))
		return (1);
	return (0);
}

int			ft_check_square(char *str, int count)
{
	int		i;
	int		blocks;

	i = 0;
	blocks = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (1);
	if (!ft_istetramino(str))
		return (1);
	return (0);
}

t_tetramino	*ft_createtetram(char *str, char sym)
{
	t_tetramino	*tet;
	int			i;
	int			j;

	i = -1;
	j = -1;
	tet = ft_newtet();
	while (str[++i])
	{
		if (str[i] == '#' && ++j == 0)
		{
			tet->p->x[j] = i / 5;
			tet->p->y[j] = i % 5;
		}
		else if (str[i] == '#' && j != 0)
		{
			tet->p->x[j] = (i / 5) - tet->p->x[0];
			tet->p->y[j] = (i % 5) - tet->p->y[0];
		}
	}
	tet->p->x[0] = 0;
	tet->p->y[0] = 0;
	tet->r = sym;
	tet->next = NULL;
	return (tet);
}

t_tetramino	*ft_readfile(int fd)
{
	char		*buf;
	int			count;
	t_tetramino	*list;
	char		symb;
	int			ff;

	buf = ft_strnew(21);
	list = NULL;
	symb = 'A';
	while ((count = read(fd, buf, 21)) > 19)
	{
		ff = count;
		if (ft_check_square(buf, count) != 0)
		{
			ft_memdel((void **)&buf);
			return (NULL);
		}
		ft_tetadd(&list, ft_createtetram(buf, symb++));
	}
	if (count != 0 || ff == 21 || symb > 'A' + 26)
		return (NULL);
	ft_memdel((void **)&buf);
	return (list);
}
