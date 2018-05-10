/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:29:38 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/20 17:09:05 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

void	ft_printmap(t_map *list)
{
	int		i;
	int		j;

	i = -1;
	while (++i < list->size)
	{
		j = -1;
		while (++j < list->size)
		{
			ft_putchar(list->map[i][j]);
		}
		ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	t_tetramino	*list;
	t_map		*map;

	if (ac != 2)
	{
		ft_putstr("usage is not defined! Be careful pls :)\n");
		return (0);
	}
	else
	{
		if (!(list = ft_readfile(open(av[1], O_RDONLY))))
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	map = ft_mapping(&list);
	ft_printmap(map);
	ft_freetet(&list);
	return (0);
}
