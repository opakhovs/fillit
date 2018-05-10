/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:14:40 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/01 14:14:41 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		while (*s1 && *s2 && (++i < n))
			if (*s1++ != *s2++)
				return (0);
		if ((!*s1 && !*s2) || (*s1 == *s2))
			return (1);
	}
	return (0);
}
