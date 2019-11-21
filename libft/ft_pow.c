/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:18:52 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/21 19:37:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Возвращает число
*/

int	ft_pow(int number, int pow)
{
	int	i;
	int res;

	i = 0;
	res = 1;
	if (number == 0 || pow < 0)
		return (0);
	while (i < pow)
	{
		res *= number;
		i++;
	}
	return (res);
}
