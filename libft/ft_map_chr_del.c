/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_chr_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:45:04 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/21 19:37:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_map_chr_del(char **map, size_t row)
{
	while (row)
	{
		free(map[row - 1]);
		map[row - 1] = NULL;
		row--;
	}
	free(map);
}
