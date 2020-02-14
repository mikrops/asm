/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:43:44 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Возвращает двумерный массив символов размерами row x col
*/

char	**ft_map_char(int row, int col)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)ft_memalloc(sizeof(char *) * (row + 1));
	map[row] = NULL;
	while (i < row)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * col + 1);
		map[i][col] = '\0';
		i++;
	}
	return (map);
}
