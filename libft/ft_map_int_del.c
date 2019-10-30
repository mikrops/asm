/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_int_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:40:33 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:03:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_map_int_del(int **map, size_t row)
{
	while (row)
	{
		free(map[row - 1]);
		map[row - 1] = NULL;
		row--;
	}
	free(map);
}
