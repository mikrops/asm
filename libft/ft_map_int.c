/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:25:59 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/21 19:37:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Возвращает двумерный массив чисел(int) размерами row x col
*/

int	**ft_map_int(int row, int col)
{
	int	**heatmap;
	int	i;

	i = 0;
	heatmap = (int **)ft_memalloc(sizeof(int *) * (row + 1));
	while (i < row)
	{
		heatmap[i] = (int *)ft_memalloc(sizeof(int) * col + 1);
		i++;
	}
	return (heatmap);
}
