/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map_chr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:02:26 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:03:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Выводит двумерный симвлоьный массив размерами row x col в поток fd
*/

void	ft_put_map_chr_fd(char **map, int row, int col, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < row)
	{
		while (i < col)
		{
			ft_putchar_fd(map[j][i], fd);
			i++;
		}
		ft_putstr_fd("\n", fd);
		i = 0;
		j++;
	}
}
