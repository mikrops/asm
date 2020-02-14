/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:54:16 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Выделение памяти под двумерный массив void
*/

void	**ft_map_void(int row, int col, size_t size_row, size_t size_col)
{
	int		i;
	void	**map;

	i = 0;
	map = (void **)ft_memalloc(size_row * (row + 1));
	map[row] = NULL;
	while (i < row)
	{
		map[i] = (void *)ft_memalloc(size_col * (col + 1));
		i++;
	}
	return (map);
}
